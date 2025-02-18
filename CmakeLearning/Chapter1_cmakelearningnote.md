1.Cmake 使用
    a.需要写CmakeLists.txt文件
    b.在创建一个文件夹bulider来存放运行cmake生成的文件
    c.在bulider中使用make进行构建编译,可以通过-j4来指定使用的线程数,加快编译速度,也可以用cmake --build进行构建
    ******
    从中遇到的问题，较多的编译错误，对模板函数的声明定义和使用不熟悉


    Linux 的动态库和静态库是什么？
    在 Linux 中，静态库和动态库是两种用于代码共享和复用的库文件类型。

**静态库（Static Library）**：

静态库在链接时被完整地复制到可执行文件中。这意味着如果多个程序都使用了同一个静态库，那么每个程序都会包含该库的一份副本，这会增加可执行文件的大小。

静态库的文件扩展名通常是 `.a`（在 Linux 中）。创建静态库通常使用 `ar` 工具。

优点：
1. 部署相对简单，因为可执行文件不依赖于外部的库文件。
2. 运行时的性能可能稍好，因为不需要在运行时进行库的加载和链接。

缺点：
1. 生成的可执行文件较大。
2. 对库的更新需要重新编译链接所有使用该库的程序。

**动态库（Dynamic Library / Shared Library）**：

动态库在程序运行时被动态加载和链接。多个程序可以共享同一个动态库在内存中的副本，从而节省内存空间。

动态库的文件扩展名通常是 `.so`（在 Linux 中）。

优点：
1. 生成的可执行文件较小，因为库没有被包含在其中。
2. 对库的更新不需要重新编译使用该库的程序，只需要更新库文件本身。

缺点：
1. 部署相对复杂，因为需要确保运行环境中存在所需的动态库并且路径正确。
2. 可能存在版本兼容性问题。

    Try catch 的面试解释
    在面试中描述 `try-catch` 流程时，您可以按照以下方式进行：

首先，解释 `try-catch` 是 C++ 中用于异常处理的机制。

然后，详细说明其工作流程：

1. 将可能会抛出异常的代码放在 `try` 块中。
2. 如果在 `try` 块中的代码执行过程中抛出了异常，程序的控制流会立即跳转到与之匹配的 `catch` 块。
3. `catch` 块用于捕获和处理特定类型的异常。可以有多个 `catch` 块来处理不同类型的异常，按照从具体到通用的顺序排列。
4. 强调异常对象的传递，通过在 `catch` 语句的括号中指定异常类型，可以获取到被抛出的异常对象，从而获取有关异常的信息，以便进行适当的处理和错误报告。
5. 提及如果没有匹配的 `catch` 块来处理抛出的异常，程序通常会终止。

例如：“在 C++ 中，`try-catch` 机制为我们提供了一种处理运行时异常的结构化方法。我们把可能引发异常的关键代码放在 `try` 块内。一旦有异常抛出，程序就会中断 `try` 块内的执行，然后在后续的 `catch` 块中寻找能够处理该异常类型的部分。如果找到了匹配的 `catch` 块，就执行其中的处理代码，以实现对异常情况的响应和恢复操作。”

最后，您可以举例说明一个简单的 `try-catch` 代码片段来进一步加强您的描述。

    模板问题的解决，可以是把模板函数定义在头文件
    这个错误通常表示在链接阶段找不到您定义的模板函数的具体实现。

当您使用模板函数时，C++ 编译器在实例化模板时才会生成具体的函数代码。但在某些情况下，特别是在多个文件的项目中，如果模板函数的实现放在了单独的 `.cpp` 文件中，而不是在头文件中，可能会导致链接错误。

为了解决这个问题，您有几种选择：

1. 将模板函数的实现放在头文件中（`.h`）。因为模板的代码需要在使用的地方可见，以便正确实例化。

2. 如果您坚持将模板函数的实现放在 `.cpp` 文件中，那么需要确保这个 `.cpp` 文件被编译并链接。一种常见的方法是在 `CMakeLists.txt` 中明确地将包含模板实现的 `.cpp` 文件添加到可执行文件的源文件列表中。

例如，如果您的模板实现在 `template_impl.cpp` 中，您可以在 `CMakeLists.txt` 中这样修改：

```cmake
add_executable(MyAppSwapValue main.cpp template_impl.cpp)

```

# 关于其他make的方式
在使用 CMake 配置项目后，可以通过以下方式构建项目：

---

### 1. **使用 `make` 构建**
这是最常见的方式，适用于生成 Makefile 的项目。

#### 步骤：
1. 在项目根目录下创建一个 `build` 目录（推荐）：
   ```bash
   mkdir build
   cd build
   ```
2. 运行 CMake 生成 Makefile：
   ```bash
   cmake ..
   ```
3. 使用 `make` 构建项目：
   ```bash
   make
   ```
4. （可选）指定构建目标：
   ```bash
   make <target_name>
   ```
5. （可选）并行构建（加快构建速度）：
   ```bash
   make -j4  # 使用 4 个线程
   ```

---

### 2. **使用 `ninja` 构建**
`ninja` 是一个更快的构建工具，适合大型项目。

#### 步骤：
1. 在项目根目录下创建一个 `build` 目录：
   ```bash
   mkdir build
   cd build
   ```
2. 运行 CMake 并指定生成器为 `Ninja`：
   ```bash
   cmake -G Ninja ..
   ```
3. 使用 `ninja` 构建项目：
   ```bash
   ninja
   ```
4. （可选）并行构建：
   ```bash
   ninja -j4  # 使用 4 个线程
   ```

---

### 3. **使用 IDE 构建**
如果使用 IDE（如 Visual Studio、Xcode、CLion 等），CMake 可以直接生成 IDE 的项目文件。

#### 示例：生成 Visual Studio 项目
1. 在项目根目录下创建一个 `build` 目录：
   ```bash
   mkdir build
   cd build
   ```
2. 运行 CMake 并指定生成器为 Visual Studio：
   ```bash
   cmake -G "Visual Studio 17 2022" ..
   ```
3. 打开生成的 `.sln` 文件，使用 Visual Studio 构建。

#### 示例：生成 Xcode 项目
1. 在项目根目录下创建一个 `build` 目录：
   ```bash
   mkdir build
   cd build
   ```
2. 运行 CMake 并指定生成器为 Xcode：
   ```bash
   cmake -G Xcode ..
   ```
3. 打开生成的 `.xcodeproj` 文件，使用 Xcode 构建。

---

### 4. **使用 CMake 直接构建**
CMake 提供了 `--build` 选项，可以直接调用底层构建工具。

#### 步骤：
1. 在项目根目录下创建一个 `build` 目录：
   ```bash
   mkdir build
   cd build
   ```
2. 运行 CMake 生成构建系统：
   ```bash
   cmake ..
   ```
3. 使用 CMake 构建项目：
   ```bash
   cmake --build .
   ```
4. （可选）指定构建目标：
   ```bash
   cmake --build . --target <target_name>
   ```
5. （可选）并行构建：
   ```bash
   cmake --build . --parallel 4  # 使用 4 个线程
   ```

---

### 5. **清理构建**
#### 使用 `make` 清理：
```bash
make clean
```

#### 使用 `ninja` 清理：
```bash
ninja clean
```

#### 使用 CMake 清理：
```bash
cmake --build . --clean-first
```

---

### 6. **安装构建结果**
如果项目中定义了 `install` 目标，可以将构建结果安装到指定目录。

#### 使用 `make` 安装：
```bash
make install
```

#### 使用 `ninja` 安装：
```bash
ninja install
```

#### 使用 CMake 安装：
```bash
cmake --build . --target install
```

---

### 7. **其他构建选项**
- **指定构建类型**（如 Debug 或 Release）：
  ```bash
  cmake -DCMAKE_BUILD_TYPE=Debug ..
  ```
- **指定编译器**：
  ```bash
  cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ..
  ```
- **指定安装前缀**：
  ```bash
  cmake -DCMAKE_INSTALL_PREFIX=/usr/local ..
  ```

---

### 总结
| 构建方式       | 命令示例                          | 适用场景                     |
|----------------|-----------------------------------|------------------------------|
| `make`         | `make` 或 `make -j4`             | 通用，适合小型到中型项目     |
| `ninja`        | `ninja` 或 `ninja -j4`           | 大型项目，构建速度快         |
| IDE            | 生成 `.sln` 或 `.xcodeproj`      | 使用 Visual Studio 或 Xcode  |
| CMake 直接构建 | `cmake --build .`                | 跨平台，无需关心底层工具     |
| 安装           | `make install` 或 `ninja install`| 将构建结果安装到系统目录     |

根据项目需求选择合适的构建方式！