<h1 align="center">
	<a href="https://github.com/KeyC0de/CoolPrototypeDesignPattern">Cool Prototype Pattern</a>
</h1>
<hr>

Implementing Prototype Design Pattern like a boss and then laughing it out.</br>
Bonus: lewd way of spawning arrays of objects from a prototypical instance.

The prototype pattern is used when the type of object(s) to create is determined by a prototypical instance, which is cloned to produce new objects. This pattern is used to:

- avoid subclasses of an object creator in the client application, like the factory pattern does
- avoid the inherent cost of creating a new object in the standard way (like using `new`) when it is prohibitively expensive for a given application

Design

1. define a `Prototype` class with a `clone()` method that returns a copy of itself
2. create subclasses of Prototype which describe the concrete types. Implement the `clone` method (and whichother method you want of course)
3. create a `Spawner`/`Factory` class with a private `Prototype` pointer (sort of like the Queen bee who never leaves the hive) and a `spawnObject()` method. The Spawner class resembles a `PrototypeFactory` class
4. in the factory class call the prototype's `clone` method to return a copy of the prototype object based on the concrete subobject.

Notice there is a 1-to-1 relationship between a prototype and a factory. So create as many prototypical objects and their respective factory/spawner objects as the concrete subclasses you want to create.

Prototype objects can be added and removed at run-time. One neat aspect about this pattern is that it doesn't just `clone` the class of the prototype, it clones its state too. This means we could make a spawner for fast ghosts, weak ghosts, or slow ghosts just by creating an appropriate prototype ghost.

Prototype bears similarity or overlaps with Abstract Factory design pattern. Prototype does not require subclassing, but it does require an 'initialize' operation. Factory method requires subclassing, but does not require initialization. Personally I prefer Prototype, I've never used Abstract Factory.

I used Windows 8.1 x86_64, Visual Studio 2017, C++17 to build the project.


# Contribute

Please submit any bugs you find through GitHub repository 'Issues' page with details describing how to replicate the problem. If you liked it or you learned something new give it a star, clone it, contribute to it whatever. Enjoy.


# License

Distributed under the GNU GPL V3 License. See "GNU GPL license.txt" for more information.


# Contact

email: *nik.lazkey@gmail.com*</br>
website: *www.keyc0de.net*
