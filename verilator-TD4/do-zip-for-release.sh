#!/bin/bash
# zip for release
#
# example: ./do-zip-for-release.sh

#cwd=`pwd`
#
#pushd ..
# -j: junk paths, ignore directory structure
#zip -j ${cwd}/soft-FPGA-TD4-v0.1-alpha.zip ./README_jp.md ${cwd}/build/{test.uf2,test.elf}
zip -j soft-FPGA-TD4-v0.1-alpha.zip ../README_jp.md ./build/{test.uf2,test.elf}
#popd
#
