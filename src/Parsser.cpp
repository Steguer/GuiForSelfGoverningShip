#include "Parsser.hpp"

string Parsser::m_filePath = "../../rsc/config.json";

Parsser::Parsser()
{

}

Parsser::~Parsser()
{

}

string Parsser::getFilePath()
{
	return m_filePath;
}

void Parsser::setFilePath(string const& newFilePath)
{
	m_filePath = newFilePath;
}
