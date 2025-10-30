# FAQ

## Q1-verilator出力のC++ソースを修正する必要はあるか？

- A: __ありません。__
- verilatorはLinux向けビルドを想定しているので、出力C++ソースではpthread mutexを使っています。
- pico SDKはpthread mutexをサポートしていないので、そのままではコンパイルエラーになります。(verilatorのフラグオプションで thread 1に指定してもmutexを使う)

- 何もしないダミーmutexクラスをヘッダーファイル`stub_mutex.h`で定義することにより、pico SDK C++でビルドできるようにしています。
- 通常であれば、`stub_mutex.h`をverilator出力のCPPソースの先頭に`#include "stub_mutex.h"`と書けばコンパイルできるようになります。
- しかしながら、verilator変換は何度も実行するので、その度に毎回出力ソースファイルを修正するのは手間がかかります。
- そこで、ヘッダーファイル`stub_mutex.h`を読み込むようにg++フラグオプションで指定します。

  ```bash
  g++ -include stub_mutex.h -o output source.cpp
  ```

- `-include` オプション
  - 特定のヘッダーファイルを強制的にインクルードします。ソースコードに `#include` を書かなくても、指定したヘッダーファイルが自動的にインクルードされます。
- 実際は`CMakeLists.txt`に書かれています。
  - [CMakeLists.txt](./verilator-TD4/CMakeLists.txt)

  ```text
      # dir_obj/*.cppに -include stub_mutex.h を適用
      set_source_files_properties(${VERILATOR_SOURCES} PROPERTIES COMPILE_FLAGS "-include stub_mutex.h")
  ```

- 結論
  - verilatorの出力C++ソースを修正する必要はありません。

---
