# reel_control
## 使っているもの
制御基板
- Arduino nano

モータードライブ基板
- A4988

ステッピングモーター
- ST-42BYH1004

## モータードライブ基板について
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

## 配線について
### Arduino側
制御には、DIR・STEPを使う。<br>
SLEEPとRESETは、短絡させる。<br>

|  | DIR | STEP |
| :----: | :----: | :----: |
| 役割 | 左右方向指定 |　回転指定 |
| プログラム | LOW/HIGH | HIGH |

#### DIRの使い方
|  | 左 | 右 |
| :----: | :----: | :----: |
| プログラム | HIGH | LOW |

#### STEPの使い方
STEPのHIGHとLOWを繰り返す。<br>
`400`は、ステップ数。<br>
ここで使っているモーターは、`400ステップ`で一回転する。<br>
`delayMicroseconds(2000)`は、変更しないほうが良い。(脱調する)

``` c
for(i = 0; i <= 400; i++){
    digitalWrite(STEP, HIGH);
    delayMicroseconds(2000);
    digitalWrite(STEP, LOW);
    delayMicroseconds(2000);
  }
```

### モーター側
VMOTは、モーター電源。<br>
VDDは、基板電源。Arduinoから取ってよい。<br>

#### A1、A2、B1、B2の使い方
ここで使っているモーターの配線の色と対応している表。
|  | B1 | A1 | A2 | B2 |
| :----: | :----: | :----: | :----: | :----: |
| 配線色 | Black | Green | Red | Blue |