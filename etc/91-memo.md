
# メモ

- `Raspberry Pi 5`で`soft-FPGA`できるかも？
  - `Raspberry Pi OS`はLinuxなので、pthread mutexに対応している。
  - verilator出力のC++ソースがそのまま動く見込み。
    - pico2のようにmutexを無効化する必要がないと思われる。（未検証）
  - ラズパイ5の`soft-FPGA`でLチカ
  - 簡単なので試す価値あり。
- `Raspberry Pi OS`
  - Linuxなのでリアルタイム処理が弱い。
    - リアルタイム処理にはPREEMPT_RTパッチを適用したカーネルが推奨
    - リアルタイム向けのOS設定
- `Raspberry Pi 5`で`FreeRTOS`
  - 高度なリアルタイム要件（マイクロ秒単位の制御）なら、FreeRTOSを検討。
    - ただし、Pi 5のフル機能は制限される場合あり。
  - `Raspberry Pi 5`向けの`FreeRTOS`公式サポートはない。
- しかし、もともと`soft-FPGA`は遅いので、リアルタイム性を追求する意味はあまりないかも？実験としてラズパイ5で十分である。
- リアルタイム性が高まると実験できる範囲が広がる。
  - DSP処理など。
- pico2の方が`soft-FPGA`向きなので依然として`pico2`で動く意味はある。
  - pico2の方がGPIOが速い。
  - GPIO低レイテンシと高い応答性
  - pico2の方が安価
  - pico2にはADC(アナログデジタル変換)がある。ADCを用いた`soft-FPGA`実験ができる。ラズパイ5にはない。
- pico2のADCを使った`soft-FPGA`実験
  - FIRフィルター実験(リアルタイムDSP処理)
    - `Grok`に聞いてみた。verilogソースあり。
      - [01-FIR-filter-verilog.pdf](./01-FIR-filter-verilog.pdf)
    - pico2のADCで音声帯域の信号をアナログ入力
    - verilogでFIRフィルターを記述
      - まずはLPF(低周波フィルター）
      - 他にはHPF(高周波フィルター）、BPF（バンドパスフィルター）など。
    - pico2 `soft-FPGA`実行
    - pico2 PWMでデジタルアナログ変換
      - PWM出力ピンにLPF(低周波フィルター）回路を追加
    - LPF出力をオシロスコープなどで確認
- pico2 `FreeRTOS`
  - 公式サポートあり。pico SDKが使える。
  - 対話的なプログラムを開発しやすい？
    - 自作CPU用の機械語モニタ
  - `FreeRTOS`の学習に。
  
- verilogでオセロ作れるか？
  - 調査した範囲では作れそうだ。
  - `Grok`に聞いてみた。verilogソースあり（未検証）
    - [02-othello-verilog.pdf](./02-othello-verilog.pdf)
  - UI(盤面の表示、指し手の位置指定など)をpico SDK C++で書き、`soft FGPA`でverilogオセロ部分を実行する。
  - 実は、オセロマシンを作る妄想を昔からしていた。
    - 最初は`74シリーズTTL`で作る妄想をしていた。
    - 次は`FPGA`で作る妄想をしていた。
    - C言語で簡単なオセロ対戦ゲームを作ったことはある。
    - `自作CPUを語る会`でオセロ対戦の話がでてきて __びっくり__ した！
    - 忘れかけていた青春の妄想が今よみがえる！
    - `soft-FPGA`で作る __妄想が始まってしまった！__
    - 作るでしょ！今なら`soft-FPGA`でオセロ作るしかない！

- `soft-FPGA`の哲学的解釈
  - 速度の違いはあるものの、pico2を隠せば、見た目だけでは`soft-FPGA`とハードウェアFPGAは区別ができない。
  - 人間に区別できないものは、人間にとって同じということである。
  - [不可知論](https://ja.wikipedia.org/wiki/%E4%B8%8D%E5%8F%AF%E7%9F%A5%E8%AB%96) によってハードウェアFPGAと同一とみなせる。

    ```text
    不可知論（ふかちろん、agnosticism）は、
    神や超自然的な存在の有無について、
    知識として確定的な結論を下すことができないとする立場です。
    「知ることができない」という意味です。
    ```

---
