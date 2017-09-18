//
//  main.c
//  JVM-SB-2-2017
//
//  Created by Paulo Passos on 17/09/17.
//  Copyright © 2017 Paulo Passos. All rights reserved.
//

#include <stdio.h>
#include "LEITOR-EXIBIDOR/structures.h"
#include "LEITOR-EXIBIDOR/leitor.h"
#include "LEITOR-EXIBIDOR/exibidor.h"


int main(int argc, const char * argv[]) {
    
    printf("Hello, World!\n");
    
    EX_imprimirClassFile(LE_lerArquivo("/Users/paulopassos/Documents/GitHub/JVM-SB-2-2017/JVM-SB-2-2017/LEITOR-EXIBIDOR/File.class"));
    return 0;
}
