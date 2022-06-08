# ETロボコン2022
ろぼ魂チームgithubです。
※vscodeのターミナルのシェルはbashにしてください。(rbashだとcdコマンドが使えない)
そのあとにターミナルでupdateと打ってください

## 準備

### clone
```bash
cd ~/etrobo/workspace
git clone https://github.com/primary-robocon/robocon
```

### ユーザー設定
許可されたユーザーしかcommitができない可能性があるので、以下のユーザー設定を行ってください。なお、登録する情報はアクセスしているgithubアカウントの情報でなければなりません。
```bash
git config user.email "メールアドレス"
git config user.name "ユーザー名"
```

### 最後に
最後にすぐに実行できる状態に戻すため、cdで元のディレクトリに戻りましょう。
```bash
cd ~/etrobo
```

## 実行
初回実行時は下記のコマンドを実行するとシミュレータを起動し、プログラムを動かすことができます。
```bash
make app=robocon sim up
```
対象とするディレクトリを変更しない限りは、下記のコマンドを実行するだけで起動できます。
```bash
make sim up
```

## gitの操作をする前に

### 最初に
roboconディレクトリの操作をするため、まずはroboconディレクトリに移動する必要があります。
```bash
cd ~/etrobo/workspace/robocon
```

### 最後に
以下に記述されている各種操作が終わったら、いつでも実行できるようにするため、元のディレクトリに戻りましょう。
```bash
cd ~/etrobo
```

## git 各種操作

### git add
addを行うことで、指定されたファイルをステージングします。addを行わなければcommitで変更が保存されることはありません。
```bash
git add ファイル名
```
すべてのファイルをaddしたい場合
```bash
git add .
```

### git commit
git addにてステージングがあったファイルのみ変更を確定します。
```bash
git commit -m "コミットメッセージ"
```

### git push
pushを行うことで、ローカルレポジトリの内容をリモートへ反映することが出来ます。実際に反映されたかは、Githubのページを見ると分かります。なお、pushで反映されるのはcommitされたファイル群のみです。
```bash
git push
```

### git pull
pullを行うことで、リモートレポジトリに他の人がコミットした内容をローカルレポジトリに反映することができます。
```bash
git pull
```

### git rm
git rmを行うことで、指定したファイルを削除することができます。
```bash
git rm ファイル名
```

### git status
git statusにより、現在レポジトリの状況を調べることができます。ファイルの追加、編集、削除などをの状況を確認したいときに使用されます。
```bash
git status
```

## 参考サイト
[基本操作（clone、add、commit、pushなど）を覚えて、開発出来るようになる](https://www.yoheim.net/blog.php?q=20140104)

[Gitの基本操作](https://qiita.com/tetsu-upstr/items/ba844bcc353f1a2e8596)
<!--
編集者
杉本
-->
