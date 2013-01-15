#ifndef UTILS_H
#define UTILS_H

#include "tinyxml.h"

const unsigned int NUM_INDENTS_PER_SPACE=2;

const char * getIndent( unsigned int numIndents );

const char * getIndentAlt( unsigned int numIndents );

int dump_attribs_to_stdout(TiXmlElement* pElement, unsigned int indent);

void dump_to_stdout( TiXmlNode* pParent, unsigned int indent = 0 );

void dump_to_stdout(const char* pFilename);

#endif /* UTILS_H */
