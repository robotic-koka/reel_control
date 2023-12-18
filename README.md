# reel_control
## 使っているもの
制御基板
- Arduino nano

モータードライブ基板
- A4988

ステッピングモーター
- ST-42BYH1004

## モータードライブ基板について
基板についているピンの意味は、表の通り。<br>
基板は、下に半固定抵抗が来るように見る。<br>

|  | モータードライブ |  |
| :----: | :----: | :----: |
| Arduino側 |  | モーター側 |
|  |  |  |
| ENABLE |  | VMOT |
| MS1 |  | GND |
| MS2 |  | B2 |
| MS3 |  | A2 |
| RESET  |  | A1 |
| SLEEP |  | B1 |
| STEP |  | VDD |
| DIR | 半固定抵抗 | GND |

## 配線とプログラムについて
### Arduino側
制御には、DIRとSTEPを使う。<br>
SLEEPとRESETは、短絡させる。<br>

|  | DIR | STEP |
| :----: | :----: | :----: |
| 役割 | 回転方向指定 |　ステップ数指定 |
| プログラム | LOW/HIGH | LOW/HIGH |

#### DIRの使い方
回転方向は、DIRピンを`HIGH`か`LOW`にすることで変えられる。<br>

| 回転方向 | 左 | 右 |
| :----: | :----: | :----: |
| プログラム | HIGH | LOW |

#### STEPの使い方
STEPのHIGHとLOWを繰り返す。<br>
`400`は、ステップ数。<br>
ここで使っている[モーター]( #使っているもの )は、`400ステップ`で一回転する。<br>
`delayMicroseconds(2000)`は、変更しないほうが良い。(脱調する)<br>

``` c
for(i = 0; i <= 400; i++){
    digitalWrite(STEP, HIGH);
    delayMicroseconds(2000);
    digitalWrite(STEP, LOW);
    delayMicroseconds(2000);
  }
```

### モーター側
VMOTは、モーター電源。電池を使う。(5V)<br>
VDDは、基板電源。Arduinoから取ってよい。<br>

#### A1、A2、B1、B2の使い方
ここで使っている[モーター]( #使っているもの )の配線の色と対応している表。
| モータドライブ基板 | B1 | A1 | A2 | B2 |
| :----: | :----: | :----: | :----: | :----: |
| モーター配線 | Black | Green | Red | Blue |
