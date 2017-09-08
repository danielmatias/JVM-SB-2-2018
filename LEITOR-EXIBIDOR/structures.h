/** ********************************************************************************
 *
 *  Universidade de Brasilia - 02/2017
 *	Software Basico - Turma A
 *
 *	@defgroup MODULO ESTRUTURAS
 *  @{
 *  @ingroup MOD_ES
 *
 *  @file structures.h
 *  @brief 
 *			Modulo de definicao: Modulo Estruturas:
 *         	Define as estruturas do bytecode.
 *
 * @author PAULO DA CUNHA PASSOS - MAT. 10/0118577
 * @version 1.0
 * @since 07/09/2017
 *
 @}********************************************************************************/

/* Controle de escopo do arquivo de definicao */
#ifndef	STRUCTURES_H
#define STRUCTURES_H

/** ******************************************************************************
* 							Inclusao do compilador 
** *******************************************************************************/

/* Inclusao de biblioteca para tratamento de tipo inteiro com representatividade
alternada de acordo com a quantidade de bits*/
#include <stdint.h>


/* Definições de tipos de dados*/
typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;


/** ******************************************************************************
*							TEBELA POOL DE CONSTANTES
** *******************************************************************************/

/**							 DEFINIÇÕES DE TAGS									**/
#define CONSTANT_Utf8 1
#define CONSTANT_Float 4
#define CONSTANT_Integer 3
#define CONSTANT_Long 5
#define CONSTANT_Double 6
#define CONSTANT_Class 7
#define CONSTANT_String 8
#define CONSTANT_Fieldref 9
#define CONSTANT_Methodref 10
#define CONSTANT_InterfaceMethodref 11
#define CONSTANT_NameAndType 12

/** 							ESTRUTURAS 										**/

typedef struct{
	u1 tag; 
	u1 info[];
}cp_info;

/* Representa valores strings constantes, inclusive Unicode */
typedef struct{
	u1 tag;
	u2 length;
	u1 *bytes;
}CONSTANT_Utf8_info;

/* Representa uma constante de ponto flutuante de 4 bytes */
typedef struct{
	u1 tag;
	u4 bytes;
}CONSTANT_Float_info;

/* Representa uma constante inteira de 4 bytes */
typedef struct{
	u1 tag;
	u4 bytes;
}CONSTANT_Integer_info;

/* Representa uma constante inteira de 8 bytes */
typedef struct{
	u1 tag;
	u4 high_bytes;
	u4 low_bytes;
}CONSTANT_Long_info;

/* Representa constante de ponto flutuante de 8 bytes */
typedef struct{
	u1 tag;
	u4 high_bytes;
	u4 low_bytes;
}CONSTANT_Double_info;

/* Representa uma Classe ou Interface */
typedef struct{
	u1 tag;
	u4 name_index;
}CONSTANT_Class_info;

/* Representa objetos constantes do tipo String */
typedef struct{
	u1 tag;
	u2 string_index;
	//GLOBAL_HEAP StringObject;
}CONSTANT_String_info;

/* Representa um field */
typedef struct{
	u1 tag;
	u2 class_index;
	u2 name_and_type_index;
}CONSTANT_Fieldref_info;

/* Representa um método */
typedef struct{
	u1 tag;
	u2 class_index;
	u2 name_and_type_index;
}CONSTANT_Methodref_info;

/* Representa uma interface */
typedef struct{
	u1 tag;
	u2 class_index;
	u2 name_and_type_index;
}CONSTANT_InterfaceMethodref_info;

/* Representa um field ou método sem indicar classe ou interface a que pertence */
typedef struct{
	u1 tag;
	u2 name_index;
	u2 descriptor_index;
}CONSTANT_NameAndType_info;

/** ******************************************************************************
*								FLAGS DE ACESSO
** *******************************************************************************/

/**							 DEFINIÇÕES DE TAGS									**/
#define ACC_PUBLIC 		0X0001
#define ACC_FINAL 		0X0002
#define ACC_SUPER 		0X0003
#define ACC_INTERFACE 	0X0200
#define ACC_ABSTRACT 	0X0400
#define ACC_SYNTHETIC	0x1000
#define ACC_ANNOTATION	0x2000
#define ACC_ENUM		0x4000

/** ******************************************************************************
*								TABELA DE INTERFACE
** *******************************************************************************/
typedef struct{
	u2 constant_pool_index;
	struct interface_list *next;
}interface_list;

/** ******************************************************************************
*								TABELA DE ATRIBUTOS
** *******************************************************************************/
typedef struct{
	u2 attribute_name_index;
	u4 attribute_length;
	u1 *info;
	struct attribute_info *next;
}attribute_info;

/** ******************************************************************************
*								TABELA DE CAMPOS (FIELD)
** *******************************************************************************/
typedef struct{ 
	u2 access_flags;
	u2 name_index;
	u2 descriptor_index;
	u2 attributes_count;
	attribute_info attributes;
	struct field_info *next;
	//attribute_info attributes[attributes_count];
}field_info; 

/** ******************************************************************************
*								TABELA DE METODOS
** *******************************************************************************/
typedef struct{
	u2 access_flags;
	u2 name_index;
	u2 descriptor_index;
	u2 attributes_count;
	attribute_info attributes;
	struct method_info *next;
	//attribute_info attributes[attributes_count];
}method_info;  

/** ******************************************************************************
*								TABELA DE EXCESSÃO
** *******************************************************************************/
typedef struct{ 		
	u2 start_pc;
	u2 end_pc;
	u2 handler_pc;
	u2 catch_type;  
}exception_table;

/** ******************************************************************************
*								ATRIBUTO CODE
** *******************************************************************************/
typedef struct{
	u2 attribute_name_index;
	u4 attribute_length;
	u2 max_stack;
	u2 max_locals;
	u4 code_length;
	u1 *code;
	//u1 code[code_length];
	u2 exception_table_length;
	exception_table exception_table;
	u2 attributes_count;
	attribute_info attribute_info;
	//attribute_info attributes[attributes_count];
}code_attribute; 

/** ******************************************************************************
*								ATRIBUTO EXCEPTIONS
** *******************************************************************************/
typedef struct {
	u2 attribute_name_index;
	u4 attribute_length;
	u2 number_of_exceptions;
	//u2 exception_index_table[number_of_exceptions];
}exceptions_attribute;


/** ******************************************************************************
*								ESTRUTURA CLASSFILE
** *******************************************************************************/
typedef struct{
	wchar_t *fully_qualified_name;	
	u4	magic;						// Assinatura de um arquivo .class
	u2 	minor_version_number;		// Versao minima do arquivo - Relacao com a versao do Java
	u2	major_version_number;		// Versao manima do arquivo - Relacao com a versao do Java
	u2	constant_pool_count;		// Numero de entradas na estrutura Constant Pool
	cp_info	*constant_pool_table;	// Tabela Constant Pool
	u2 	access_flags;				// Mascara de bits que especifica permissao de acesso da classe
	u2	this_class;					// Representa a classe definida
	u2	super_class;				// Representa a super classe direta da classe definida
	u2	interfaces_count;			// Numero de entradas na estrutura Interfaces
	u2	*interfaces_table;			// Tabela Interfaces que sao superinterfaces diretas da classe
	u2	fields_count;				// Numero de variaveis de classe ou de instacias declaradas na classe presentes na estrutura Field
	field_info 	*field_info_table;	// Tabela de Field
	u2	methods_count;				// Numero de estruturas method_info na tabela de Methods
	method_info *method_info_table;	// Tabela de Metodos
	u2	attributes_count;			// Numero de estruturas attributes_info na tabela Atributos
	attribute_info **attribute_info_table; // Tabela de Attributos
	//u2 code_index;
	//u2 main_name_index;
	//u2 start_method_index;
	//CACHE_FIELD_LOCATION cache_field_loc;
	//CACHE_FIELD_LOCATION cache_curr_loc;
	//METHOD_HASH_TABLE method_hash_table;
	//struct Class_file *right;
	//struct Class_file *left;
}classFile;

/** ******************************************************************************
*  Funcao: 
*
*  Descricao da funcao:
*      Retorna 
*
* @return 
*
** *******************************************************************************/
    
/** ******************************************************************************
*  Funcao: 
*
*  Descricao da funcao:
*      
*
* @param fim    - True : transacao finalizada.
*               - False : transacao ainda nao finalizada.
*
** *******************************************************************************/

#endif
