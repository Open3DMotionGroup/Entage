<!--
  Entage

	Copyrighted material. See LICENSE.txt for more information.
-->

# Introduction

## What is Entage?

Entage is a library for C++14 and later which lets us work with data trees (as might be loaded from JSON, BSON, YAML, etc) as if they are C++ classes. For example here is a C++ class using Entage to represent the identity of an aircraft:

```cpp
  class Identity : public Entage::CompoundView
  {
    // Construct with empty values
    // and register member variables as Entage elements
    Identity() :
      ENTAGE_MAP(Registration),
      ENTAGE_MAP(Type),
      ENTAGE_MAP(Serial)
    {
    }

    // The registration plate of the aircraft, e.g. G-BFMK
    Entage::MapValue<std::string> Registration;
    
    // The type of aircraft, e.g. C152
    Entage::MapValue<std::string> Type;

    // Serial number, e.g. 344
    Entage::MapValue<int32_t> Serial;
  };
```

And here is an example where the identity as defined above is used as a sub-component of a description of the aircraft state:

```cpp
  class Aircraft : public Entage::CompoundView
  {
  public:

    // Construct with empty values
    // and register member variables as Entage elements
    Aircraft() :
      ENTAGE_MAP(ID),
      ENTAGE_MAP(Altitude),
      ENTAGE_MAP(Latitude),
      ENTAGE_MAP(Longitude),
      ENTAGE_MAP(Heading),
      ENTAGE_MAP(Velocity)
    {
    }
    
    // Unique identity of the aircraft
    Entage::MapCompound<Identity> ID;

    // Current altitude (feet above mean sea level)
    Entage::MapValue<double> Altitude;

    // Latitude (degrees)
    Entage::MapValue<double> Latitude;

    // Longitude (degrees)
    Entage::MapValue<double> Longitude;

    // True compass heading (degrees)
    Entage::MapValue<double> Heading;

    // Velocity vector [ horizontal, vertical ] in metres per second
    Entage::MapArray<double> Velocity;
  };
```

When using Entage the member variables defined above work like native C++
primitives and classes, e.g. to set the aircraft serial number in an instance `myplane` of type `Aircraft` we can write simply:

```cpp
  myplane.ID.Serial = 344;
```
But behind the scenes such an action of setting or a getting value operates on an underlying tree structure corresponding to the class structure, rather than simply modifying a member variable.

## Why would we want to use this?

1. Saving and loading objects becomes one line of code.  Suppose we have an instance
'`myplane` of class `Aircraft` as defined above and want to save it to a file so that we
can load it again later.  Then just write:
```cpp
append_as_json(ofstream("aircraft.txt"), myplane);
```
and we get a text file that looks like:
```javascript
{ ID: { Registraton: "G-BFMK", Type: "C152", Serial: 344 }, Altitude: 2300.5, Latitude: 52.6063, Longitude: 1.0348, Heading: "285.3", Velocity: [ 51.3, 152.4 ] }
```

2. We get extensible file formats with minimal effort.  Suppose in a software update we wanted to add a `Destination` field for the flight. All we need to do is create this as
a member of the `Aircraft` class like `Entage::MapValue<std::string> Destination;` , ensure it's mapped in the constructor using `ENTAGE_MAP` and then the new field will appear in the output.

3. Loading and re-saving data created in newer versions from an older version is both
backwards compatible and non-destructive.  For example, when working with a file containing the
new `Destination` field as above, our original code (without that field) can still read the new file - it will simply ignore the field it doesn't recognise.  Not only that but the `Destination` field will still be present if the old version loads and re-saves the newer data format, because the data is kept in the underlying tree structure throughout.

4. The tree structures created are ideally suited for storage in so-called NoSQL data stores such as
MongoDB.

5. This effectively gives us the serialisation features available in higher level languages
that have reflection features (Python, Java, C#) but directly from C++.