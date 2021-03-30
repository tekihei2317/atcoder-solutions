#!/bin/sh
# testフォルダがある場合は削除する
rm -rf $PWD/test

# テストケースダウンロード
oj d $1

# ファイルを作成する
# array=( `echo $1 | tr -s '/' ' '`)
# last_index=`expr ${#array[@]} - 1`
# cp $HOME/my-projects/compro/template.php "${array[${last_index}]}.php"
