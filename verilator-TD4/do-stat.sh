#!/bin/bash
# verilogソースから統計情報(FF数など)を得る

if [[ $NAME -ne "wsl400" ]]; then
  echo "This script is intended to run in WSL environment."
  exit 1
fi

yosys -p "
  read_verilog TD4.v
  synth_xilinx -top TD4 -flatten
  #techmap
  #stat
" | \
sed -n '/Printing statistics/{n;:a; /Estimated number of LCs:/{p;b}; p; n; ba}' >TD4.v-stat.txt

gawk -n '
/^[[:space:]]+LUT/ { 
    #printf( "$2=%d\n", $2);
    total["LUT"] += $2;
}
/^[[:space:]]+(DFF|FDCE|FDRE|FDSE|FDPE)/ { 
    #printf( "$2=%d\n", $2);
    total["FF"] += $2;
}
END {
    printf( "(FPGAマッピング後に必要なロジックセルの概算数)\n")
    printf("\n");
    printf( "Total LUT=%d\n", total["LUT"]);
    printf( "Total  FF=%d\n", total["FF"]);
}
' TD4.v-stat.txt >>TD4.v-stat.txt
