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
    EX_imprimirClassFile(LE_carregarClasse("/Users/danielmatias/Desktop/JVM-SB-2-2018/LEITOR-EXIBIDOR/double_aritmetica.class"));
    return 0;
}
