#include "TextEditor.hpp"

TextEditor::TextEditor()
{
	m_lineSpace = new LineSpace(this);

	connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineSpaceWidth(int)));
	connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineSpace(QRect,int)));

	updateLineSpaceWidth(0);

	m_highlighter = new Highlighter(this->document());
}

TextEditor::~TextEditor()
{
	delete m_lineSpace;
	delete m_highlighter;
}

void TextEditor::updateLineSpaceWidth(int)
{
	 int digits = 1;
     int max = qMax(1, blockCount());
     while (max >= 10) {
         max /= 10;
         ++digits;
     }

    m_space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;

	setViewportMargins(m_space, 0, 0, 0);
}

void TextEditor::updateLineSpace(QRect const& rect, int const& dy)
{
	std::cout<<"coucou"<<std::endl;
	if (dy)
	{
         m_lineSpace->scroll(0, dy);
	}
    else
    {
        m_lineSpace->update(0, rect.y(), m_lineSpace->width(), rect.height());
    }
}

void TextEditor::resizeEvent(QResizeEvent *e)
{
	QPlainTextEdit::resizeEvent(e);

	QRect rec = contentsRect();
	m_lineSpace->setGeometry(QRect(rec.left(), rec.top(), m_space, rec.height()));
}

void TextEditor::lineSpacePaint(QPaintEvent *event)
{
	QPainter painter(m_lineSpace);
	//Set the background to lightGray to be sure of the color. 
	painter.fillRect(event->rect(), Qt::lightGray);

	QTextBlock block = firstVisibleBlock();
	int blockNumber = block.blockNumber();
	int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
	int bottom = top + (int) blockBoundingRect(block).height();

	while (block.isValid()) 
	{
	    if (block.isVisible())
	    {
	        QString number = QString::number(blockNumber + 1);
	        painter.setPen(Qt::black);
	        painter.drawText(0, top, m_lineSpace->width(), fontMetrics().height(), Qt::AlignRight, number);
	    }

	    block = block.next();
	    top = bottom;
	    bottom = top + (int) blockBoundingRect(block).height();
	    ++blockNumber;
	}
}

int TextEditor::getSpace()
{
	return m_space;
}