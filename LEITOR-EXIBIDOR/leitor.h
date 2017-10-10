//
//  leitor.h
//  JVM-SB-2-2017
//
//  Created by Paulo Passos on 17/09/17.
//  Copyright © 2017 Paulo Passos. All rights reserved.
//

#ifndef leitor_h
#define leitor_h


#include "structures.h"
#include <stdio.h>
#include <stdlib.h>

u1 LE_lerU1(FILE *pArq);

u2 LE_lerU2(FILE *pArq);

u4 LE_lerU4(FILE *pArq);

ST_tpCp_info *LE_lerConstant_pool(FILE *pArq, u2 constant_pool_count);

ST_tpClassFile *LE_carregarClasse(char *nomeArquivo);

#endif /* leitor_h */
