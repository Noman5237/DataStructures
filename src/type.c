/**
 * @file: type.c
 * @author: Anonyman637
 * @date: 8/26/2021; 3:33 PM
 */

#include <type.h>

Type *type_new(char *typeName) {
	Type *newType = malloc(sizeof(Type));
	newType->typeName = malloc(strlen(typeName) + 1);
	strcpy(newType->typeName, typeName);
	return newType;
}

void type_destroy(Type *type) {
	free(type->typeName);
	free(type);
}

Any *any_new(void *data, Type *type) {
	Any *any = malloc(sizeof(Any));
	any->data = data;
	any->type = type;
	return any;
}

/**
 * All the generic variables call this function after they have freed the data
 * in their own way. This function is meant to be only called in the type specified
 * free function and not by any other function which intents to free generic variables.
 */
void any_destroy(Any *any) {
	free(any);
}
