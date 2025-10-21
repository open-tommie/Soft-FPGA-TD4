# 開発環境インストール手順

- Windows11
- VSCode
  - `pico SDK`ではVSCodeが標準開発環境です。
- `pico SDK` VSCode拡張インストール
  - Raspberry Pi 公式の拡張機能 (Raspberry Pi Pico)
  - [Raspberry Pi Pico Visual Studio Code extension](https://github.com/raspberrypi/pico-vscode)
    - この拡張をVSCodeにインストールすると`pico SDK`がインストールされます。
    - [公式 Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk)

- verilatorインストール

  - WSL2 (Windows Subsystem for Linux)上verilatorを使用（最も簡単で推奨）
  - Windows 10/11でWSL2を有効化
  - Microsoft StoreからUbuntuインストール
  - 以下のwsl2 Ubuntu24でテストしました。

    ```bash
    $ lsb_release  -a
    No LSB modules are available.
    Distributor ID: Ubuntu
    Description:    Ubuntu 24.04.3 LTS
    Release:        24.04
    Codename:       noble
    ```

  - Ubuntuパッケージのverilatorをインストール
    - WSL内で以下を実行

    ```bash
    $ sudo apt update && sudo apt install verilator
    $ verilator --version
    Verilator 5.020 2024-01-01 rev (Debian 5.020-1)
    ```

  - 最新版のインストール
    - `soft-FPGA`はverilator 5.xxxであれば最新版でなくても動くと思います。
    - 余力があれば最新版をインストールして下さい。
    - 既にパッケージをインストールしてある場合はアンイストールします。

    ```bash
    $ sudo apt remove verilator
    ```

    - インストール手順
      - [公式：how to install Verilator.](https://verilator.org/guide/latest/install.html)

    - インストール後の確認

    ```bash
    $ which verilator
    /usr/local/bin/verilator
    $ verilator --version
    Verilator 5.040 2025-08-30 rev v5.040
    ```

---
