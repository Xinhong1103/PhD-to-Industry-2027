# C++ Memory Management & Segmentation

## 1. Memory Segments Overview
The C++ memory model is divided into four primary segments, each with specific roles and lifecycle rules.

---

## 2. Segment Breakdown

### 🟢 Code Area (Text Segment)
* **Contents**: Stores the compiled binary machine instructions (CPU executable code).
* **Characteristics**: 
    * **Read-Only**: Prevents the program from accidentally modifying its own instructions.
    * **Shared**: Allows multiple instances of the same program to share a single copy in memory.

### 🟡 Global / Static Area (Data Segment)
* **Contents**: Stores global variables, static variables, and constants.
* **Lifecycle**: Allocated at program startup; deallocated only when the program exits.
* **Sub-components**:
    * **Global Variables**: Variables defined outside the scope of any function.
    * **Static Variables**: Variables declared with the `static` keyword (retains state between function calls).
    * **Constants**: Global `const` variables and string literals (e.g., "Hello World").

### 🔵 Stack Area
* **Management**: Automatically managed by the compiler (**Automatic Memory Management**).
* **Contents**: Function parameters, local variables, and return addresses.
* **Mechanism**:
    * **Allocation**: Pushed onto the stack when a function is called (Runtime).
    * **Deallocation**: Popped off the stack when the function scope ends.
* **Efficiency**: Extremely fast (LIFO - Last In, First Out) but has limited size (typically 1MB–8MB).



### 🔴 Heap Area
* **Management**: Manually managed by the developer (**Dynamic Memory Management**).
* **Commands**:
    * **Allocation**: `new` keyword.
    * **Deallocation**: `delete` keyword.
*

# const ref and pointer
### const int& ref,常量引用,指向常量的引用,不能改值，也不能改指向。
### const int* p,常量指针,指向常量的指针,内容不可变，但指针可以指向别处。
### int* const p,指针常量,指针本身是常量,内容可以改，但指针不能指向别处。

# Object-oriented
## Object =  properties + Method
## Features: encapsulation、 inheritance、polymorphism
### encapsulation: Access Modifiers Comparison

| Modifier | Visibility | Purpose |
| :--- | :--- | :--- |
| `public:` | **Everywhere** | Interface for the user; methods and data meant to be shared. |
| `private:` | **Internal Only** | Encapsulation; hides implementation details and sensitive data. |
| `protected:` | **Class + Children** | Inheritance; allows child classes to access parent data. |

---

### Struct vs. Class (Default Behavior)
The only technical difference between a `struct` and a `class` in C++ is their **default access level**:

1. **Struct**: Members are `public` by default. (Typically used for Plain Old Data / POD).
2. **Class**: Members are `private` by default. (Used for Object-Oriented logic).
**class  ~ =  struct**:a **class** is a **struct** whose member are all private by default
**instantiation** don't need to add keyword "class" and "struct"


## 🪞 `this` vs `self`: The Identity Mapping

Both keywords represent the **current instance** of the class.

### 1. Syntactic Differences
* **C++ (`this`)**: A **hidden pointer** to the object. It's automatically available in all non-static member functions.
* **Python (`self`)**: A **required parameter**. It must be the first argument of any instance method.

### 2. Usage Table
| Scenario | C++ Syntax | Python Syntax |
| :--- | :--- | :--- |
| **Member Access** | `this->member` | `self.member` |
| **Method Call** | `this->method()` | `self.method()` |
| **Function Definition**| `void func()` | `def func(self):` |

### 3. When is it Mandatory? (Ambiguity)
In both languages, they are strictly required when a **local variable name** shadows a **member variable name**.
