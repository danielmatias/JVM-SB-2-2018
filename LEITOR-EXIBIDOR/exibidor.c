//
//  exibidor.c
//  JVM-SB-2-2017
//
//  Created by Paulo Passos on 17/09/17.
//  Copyright © 2017 Paulo Passos. All rights reserved.
//

#include "exibidor.h"


void EX_imprimirClassFile(ST_tpClassFile *classFile){
    
    
    printf("\n-----GENERAL INFORMATION-----\n\n");
    printf("Magic: %08x\n",classFile->magic);
    printf("Minor Version: %04x\n",classFile->minor_version_number);
    printf("Major Version: %04x\n",classFile->major_version_number);
    printf("Constant Pool Count: %04x\n",classFile->constant_pool_count);
    printf("Access Flags: %04x\n",classFile->access_flags);
    printf("This Class: %04x\n",classFile->this_class);
    printf("Super Class: %04x\n",classFile->super_class);
    /*printf("Interfaces Count: %04x\n",classFile->interfaces_count);
    printf("Fields Count: %04x\n",classFile->fields_count);
    printf("Methods Count: %04x\n",classFile->methods_count);
    printf("Atributes Count: %02x\n",classFile->attributes_count);*/

}
