### Encapsulation
- Packing of data and functions into a single component. 
- It allows selective hiding of properties and methods in an object by building an impenetrable wall to protect the code from accidental corruption.

### Polymorphism
- Provision of a single interface to entities of different types.
- A polymorphic type is a type whose operations can also be applied to values of some other type, or types.


### Inheritance
- When an object or class is based on another object or class, using the same implementation (inheriting from a class) specifying implementation to maintain the same behavior (realizing an interface; inheriting behavior).
- It is a mechanism for code reuse and to allow independent extensions of the original software via public classes and interfaces.


### Virtual Functions
- Run time polymorpishm
- Resolve object types at runtime

```c++
class Base
{
  public:
    virtual void show() { cout<<" In Base \n"; }
};
  
class Derived: public Base
{
  public:
    void show() { cout<<"In Derived \n"; }
};
  
int main(void)
{
    Base *bp = new Derived;
    bp->show();  // RUN-TIME POLYMORPHISM
    return 0;
}
```
