/*
 *  Phrase.cpp
 *  CreateBerkeleyPt
 *
 *  Created by Hieu Hoang on 29/07/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "/usr/local/BerkeleyDB.4.7/include/db_cxx.h"
#include "../../moses/src/Util.h"
#include "Phrase.h"
#include "Global.h"

using namespace std;

namespace MosesBerkeleyPt
{

void Phrase::CreateFromString(const std::string &phraseString)
{
	std::vector<std::string> wordsVec = Moses::Tokenize(phraseString);

	vector<string>::const_iterator iter;
	for (iter = wordsVec.begin(); iter != wordsVec.end(); ++iter)
	{
		const string &wordStr = *iter;
		Word word;
		word.CreateFromString(wordStr);
		m_words.push_back(word);
	}
}

void DebugMem(char *mem, size_t size)
{
	for (size_t i =0; i < size; i++)
		printf("%x", mem[i]);
	printf("\n");
	
}

}; // namespace



