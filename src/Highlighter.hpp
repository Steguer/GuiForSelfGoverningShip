#ifndef HIGHLIGHTER_HPP
#define HIGHLIGHTER_HPP

#include <QtWidgets>

class Highlighter: public QSyntaxHighlighter
{
Q_OBJECT

public:
	Highlighter(QTextDocument *parent);
	~Highlighter();

protected:
	void highlightBlock(const QString &text);

private:
	struct HighlightingRule
	{
		QRegExp pattern;
		QTextCharFormat format;
	};
	QVector<HighlightingRule> m_highlightingRules;

	QRegExp m_commentStartExpression;
	QRegExp m_commentEndExpression;

	QTextCharFormat m_keywordFormat1;
	QTextCharFormat m_keywordFormat2;
    QTextCharFormat m_classFormat;
    QTextCharFormat m_singleLineCommentFormat;
    QTextCharFormat m_multiLineCommentFormat;
    QTextCharFormat m_quotationFormat;
    QTextCharFormat m_functionFormat;	
};

#endif