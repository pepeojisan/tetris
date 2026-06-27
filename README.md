# Tetris

C++で制作したコンソール版テトリスです。

## 概要

同好会の活動として作成しました。

## 実装した機能

- 7種類のテトリミノ
- SRS (Super Rotation System)
- Hold
- Hard Drop
- Soft Drop
- Lock Delay
- ライン消去
- スコア表示
- Next Piece表示

## 操作方法

| キー | 動作 |
| :--- | :--- |
| `Z` | 左回転 |
| `X` または `↑` | 右回転 |
| `A` | 180°回転 |
| `←` | 左移動 |
| `→` | 右移動 |
| `C` または `Shift` | Hold |
| `Space` | Hard Drop |
| `↓` | Soft Drop |
| `R` | Restart |
| `Q` | Quit |

## 開発環境

- C++17
- g++
- Windows

## 実行方法

### コンパイル

```bash
g++ tetris.cpp -o tetris.exe
```

### 実行

```bash
./tetris.exe
```
