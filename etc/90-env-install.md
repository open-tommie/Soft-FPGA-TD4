# 開発環境インストール手順

- Windows11でビルドしています。

## VSCode

- `pico SDK`ではVSCodeが標準開発環境です。
- [Download Visual Studio Code](https://code.visualstudio.com/download)

## `pico SDK` VSCode拡張インストール

- Raspberry Pi 公式の拡張機能 (Raspberry Pi Pico)
- [Raspberry Pi Pico Visual Studio Code extension](https://github.com/raspberrypi/pico-vscode)
  - この拡張をVSCodeにインストールすると`pico SDK`がインストールされます。
  - [公式 Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk)

## MSYS2

- MSYS2上のverilatorを使用するのでMSYS2が必要です。
- MSYS2は、Windows上でGNU/Linuxのような開発環境を提供するソフトウェアパッケージです。
- [MSYS2公式(日本語)](https://www-msys2-org.translate.goog/?_x_tr_sl=en&_x_tr_tl=ja)

## verilatorインストール

- 以下、実行は __`MSYS2 UCRT64 Shell`__ で行うこと。
  - MSYS2向けverilatorは`MSYS2 UCRT64`環境が公式の推奨。
  - `MSYS2 MSYS`環境ではないことに注意。

- MSYS2のパッケージを更新
  - 最初は時間がかかります。

  ```bash
  $pacman -Syu
  ```

- MSYS2上verilatorをインストール

  ```bash
  $pacman -S mingw-w64-ucrt-x86_64-verilator
  ```

- インストール後の確認

  ```bash
  $which verilator
  /c/msys64/mingw64/bin/verilator
  $verilator --version
  Verilator 5.040 2025-08-30 rev UNKNOWN.REV
  ```

### Windows PATHの追加

- VS Codeからverilator使う場合、Windowsのシステム環境変数に `C:\msys64\ucrt64\bin`を追加
  - 再起動必要
- Windows GUIを使った設定
  - Windows11|スタートメニューで「環境変数」を検索
    - 「システム環境変数の編集」を選択。
  - 「環境変数」ウィンドウで「Path」を選択
    - 「編集」。
  - 「新規」ボタンでパス`C:\msys64\ucrt64\bin`を追加
    - OK
  - 変更後、PowerShellを起動して`$env:PATH`コマンドで確認。

    ```text
    PS C:\Users\tommie> $env:PATH
    ...;C:\msys64\ucrt64\bin;
    ```

- Windows上のからは`verilator`コマンドは実行できない。
  - シェルでPythonを実行するため。
  - `verilator_bin.exe`は実行できる。
    - C++変換は実行できる。
- PowerShellからバージョン確認例：

  ```text
  PS C:\Users\tommie> verilator_bin.exe --version
  Verilator 5.040 2025-08-30 rev UNKNOWN.REV
  ```

- 参考
  - [MSYS2にVerilatorをインストールする方法(Grokの回答です。未検証)](./14-verilator-MSYS2.pdf)

  - [公式：how to install Verilator.](https://verilator.org/guide/latest/install.html)

---
