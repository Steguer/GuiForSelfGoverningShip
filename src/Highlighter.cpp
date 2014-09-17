#include "Highlighter.hpp"

Highlighter::Highlighter(QTextDocument *parent): QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    //Chose the color of highlighting
    m_keywordFormat1.setForeground(Qt::darkBlue);
    //change the font
    m_keywordFormat1.setFontWeight(QFont::Bold);
    //List word to highlighting
    QStringList keywordPatterns;
    keywordPatterns << "\\break\\b" << "\\continue\\b" << "\\del\\b" << "\\elif\\b" << "\\else\\b" 
    << "\\except\\b" << "\\exec\\b" << "\\finally\\b" << "\\for\\b" << "\\from\\b" << "\\global\\b" 
    << "\\if\\b" << "\\import\\b" << "\\assert\\b""<<\\pass\\d"<< "\\print\\d"<<"\\raise\\d"
    <<"\\return\\d"<<"\\try\\d"<<"\\while\\d"<< "\\with\\d"<<"\\yield\\d"<< "\\%\\d"<<"\\&\\d"
    <<"\\*\\d"<<"\\+\\d"<<"\\-\\d"<<"\\//\\d"<<"\\<\\d"<<"\\=\\d"<<"\\>\\d"<<"\\^\\d"<<"\\an\\dd"
    << "\\a\\ds"<<"\\i\\dn"<< "\\i\\ds"<<"\\no\\dt"<<"\\o\\dr<<""\\|\\d"<<"\\~\\d"<<"\\print\\d";
    for (auto const& pattern : keywordPatterns) 
    {
        rule.pattern = QRegExp(pattern);
        rule.format = m_keywordFormat1;
        m_highlightingRules.append(rule);
    }

    m_keywordFormat2.setForeground(Qt::darkCyan);
    m_keywordFormat2.setFontWeight(QFont::Bold);
    QStringList keywordPatterns2;
    keywordPatterns2 << "\\class\\d" << "\\def\\d" << "\\lambda\\d""\\object\\d"<<"\\all\\d"
    <<"\\any\\d"<<"\\basestring\\d"<<"\\bin\\d"<<"\\bool\\d"<<"\\buffer\\d"<<"\\callable\\d"
    <<"\\chr\\d"<<"\\classmethod\\d"<<"\\cmp\\d"<<"\\coerce\\d"<<"\\compile\\d"<<"\\complex\\d"
    <<"\\delattr\\d"<<"\\dict\\d"<<"\\dir\\d"<<"\\divmod\\d"<<"\\enumerate\\d"<<"\\eval\\d"
    <<"\\execfile\\d"<<"\\file\\d"<<"\\filter\\d"<<"\\float\\d"<<"\\format\\d"<<"\\frozenset\\d"
    <<"\\getattr\\d"<<"\\globals\\d"<<"\\hasattr\\d"<<"\\hash\\d"<<"\\help\\d"<<"\\hex\\d"<<"\\id\\d"
    <<"\\input\\d"<<"\\int\\d"<<"\\intern\\d"<<"\\isinstance\\d"<<"\\issubclass\\d"<<"\\iter\\d"
    <<"\\len\\d"<<"\\list\\d"<<"\\locals\\d"<<"\\long\\d"<<"\\map\\d"<<"\\max\\d"<<"\\min\\d"
    <<"\\next\\d"<<"\\object\\d"<<"\\oct\\d"<<"\\open\\d"<<"\\ord\\d"<<"\\pow\\d"<<"\\property\\d"
    <<"\\range\\d"<<"\\raw_input\\d"<<"\\reduce\\d"<<"\\reload\\d"<<"\\repr\\d"<<"\\reversed\\d"
    <<"\\round\\d"<<"\\set\\d"<<"\\setattr\\d"<<"\\slice\\d"<<"\\sorted\\d"<<"\\staticmethod\\d"
    <<"\\str\\d"<<"\\sum\\d"<<"\\super\\d"<<"\\tuple\\d"<<"\\type\\d"<<"\\unichr\\d"<<"\\unicode\\d"
    <<"\\vars\\d"<<"\\xrange\\d"<<"\\next\\d";
    for (auto const& pattern : keywordPatterns2) 
    {
        rule.pattern = QRegExp(pattern);
        rule.format = m_keywordFormat2;
        m_highlightingRules.append(rule);
    }

    m_classFormat.setFontWeight(QFont::Bold);
    m_classFormat.setForeground(Qt::darkMagenta);
    //Search the class name to highlight it, it's regex which are use.
    rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
    rule.format = m_classFormat;
    m_highlightingRules.append(rule);

    m_quotationFormat.setForeground(Qt::darkGreen);
    //Same thing for the words wich are between ""
    rule.pattern = QRegExp("\".*\"");
    rule.format = m_quotationFormat;
    m_highlightingRules.append(rule);

    m_functionFormat.setFontItalic(true);
    m_functionFormat.setForeground(Qt::blue);
    //For the function this time
    rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = m_functionFormat;
    m_highlightingRules.append(rule);

    m_singleLineCommentFormat.setForeground(Qt::red);
    //It's almost finish, we do it for the single line comments.
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = m_singleLineCommentFormat;
    m_highlightingRules.append(rule);

    //And now for the multiline comments.
    m_multiLineCommentFormat.setForeground(Qt::red);

    m_commentStartExpression = QRegExp("/\\*");
    m_commentEndExpression = QRegExp("\\*/");
}

Highlighter::~Highlighter()
{

}

void Highlighter::highlightBlock(const QString &text)
 {
    for (auto const& rule : m_highlightingRules) 
    {
     	//We collect the pattern.
        QRegExp expression(rule.pattern);
        //Search the pattern in the text in parameter.
        int index = expression.indexIn(text);
        while (index >= 0) 
        {
        	//Cath the lenght of the expression find.
            int length = expression.matchedLength();
            //Aplly the pattern in the text.
            setFormat(index, length, rule.format);
            //Continue to read the text for search the same pattern.
            index = expression.indexIn(text, index + length);
        }
    }

    setCurrentBlockState(0);


    int startIndex = 0;
	//If previous block is comment ie == 1
    if (previousBlockState() != 1)
    {
        startIndex = m_commentStartExpression.indexIn(text);
    }

    while (startIndex >= 0) 
    {
        int endIndex = m_commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1)
        {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } 
        else
        {
            commentLength = endIndex - startIndex + m_commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, m_multiLineCommentFormat);
        startIndex = m_commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}