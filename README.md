# 赤外線を検知してLEDをつけるだけのプログラム

2024年度の部内大会のために作りました
Arduino IDEを使って書いています

## 修正した点

・赤外線の値が閾値を超えた際に、LEDが一定時間点灯し続けるようにした（現在1秒）


## 使用するときは

フォトトランジスタの検知範囲15°などと狭く、思うように検知ができないため
検知できる範囲を増やす工夫（純粋に数を増やすなど）をした方がよさそう
