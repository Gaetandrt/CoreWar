#!/bin/bash

rougefonce='\e[0;31m'
vertfonce='\e[0;32m'
bleufonce='\e[0;33m'
souligne='\e[4m'
neutre='\e[0;m'
jaune="\x1B[33m"
bleu="\x1B[34m"
majenta="\x1B[35m"
cyan="\x1B[36m"
blanc="\x1B[37m"

make re
nb=1
echo -e "${bleu}${souligne}\tTEST ASM${neutre}\n"
echo "Error: file extension must be .s" > error.txt

make_error() {
    ./asm/asm ${1} > res_my_asm
    Test=$(diff res_my_asm error.txt)
    if [ "$Test" = "" ]
            then
                echo -ne "${vertfonce}TEST ${nb} = ${neutre}"
                echo -n "[${1}]"
                echo -ne "${vertfonce} OK${neutre}\n"
            else
                echo -ne "${rougefonce}TEST ${nb} = ${neutre}"
                echo -n "[${1}]"
                echo -ne "${rougefonce} KO${neutre}\n"
            fi
    let 'nb=nb+1'
}

echo -ne "${bleufonce}${souligne}\tERROR HANDING\n${neutre}"
make_error "tests_asm/l."
make_error "tests_asm/fake_3.txt"
make_error "tests_asm/fake_4"
rm res_my_asm
rm error.txt