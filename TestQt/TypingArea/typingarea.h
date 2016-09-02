#ifndef INPUTAREA_H
#define INPUTAREA_H

#include <QWidget>
#include <QStyleOptionFrameV3>

class QBasicTimer;

class TypingArea : public QWidget{
	Q_OBJECT
public:
	TypingArea(QWidget* = 0);

	QSize sizeHint() const;
	QSize minimumSizeHint() const;

	inline QString getText() const { return text; }
	inline int getTypedTextPercent() const { return typedTextPercent; }
	inline int getFrameWidth() const { return frameWidth; }
	inline int getFrameRadius() const { return frameRadius; }
	inline int getTextMargin() const { return textMargin; }
	inline QColor getFrameColor() const { return frameColor; }
	inline QColor getBackColor() const { return backColor; }
	inline QColor getTypedMaskColor() const { return typedMaskColor; }
	inline QColor getTextColor() const { return textColor; }
	inline QColor getCurSymbolColor() const { return curSymbolColor; }
	inline QFont getTextFont() const { return textFont; }

public Q_SLOTS:
	inline void setText(QString text, int curSymbol = 0) {
		this->text = text;
		this->curSymbol = curSymbol;
	}
	inline void setTypedTextPercent(int typedTextPercent)
	{ this->typedTextPercent = typedTextPercent; }
	inline void setFrameWidth(int frameWidth) { this->frameWidth = frameWidth; }
	inline void setFrameRadius(int frameRadius) { this->frameRadius = frameRadius; }
	inline void setTextMargin(int textMargin) { this->textMargin = textMargin; }
	inline void setFrameColor(QColor frameColor) { this->frameColor = frameColor; }
	inline void setBackColor(QColor backColor) { this->backColor = backColor; }
	inline void setTypedMaskColor(QColor typedMaskColor)
	{ this->typedMaskColor = typedMaskColor; }
	inline void setTextColor(QColor textColor) { this->textColor = textColor; }
	inline void setCurSymbolColor(QColor curSymbolColor)
	{ this->curSymbolColor = curSymbolColor; }
	inline void setTextFont(QFont textFont) { this->textFont = textFont; }

protected:
	void paintEvent(QPaintEvent *);
	void keyPressEvent(QKeyEvent *);
	void timerEvent(QTimerEvent *);

private:
	int shiftTimer;
	
	enum {
		MIN_TEXT_LENGTH = 15,
		NORMAL_TEXT_LENGTH = 30,
		TYPED_TEXT_PERCENT = 25,
		SHIFT_STEPS = 10,
		SHIFT_INTERVAL = 10,
		CUR_SYMBOL_ZOOM = 110
	};

	QString text;
	QString errorText;
	int curSymbol;

	int typedTextPercent;
	int shift;
	int shiftStep;

	int frameWidth;
	int frameRadius;
	int textMargin;
	QColor frameColor;
	QColor backColor;
	QColor typedMaskColor;
	QColor textColor;
	QColor curSymbolColor;
	QFont textFont;

	QString frameStylesheet() const;

	QRect fullBackRect() const;
	QRect leftBackRect() const;
	QRect rightBackRect() const;
	QRect fullTextRect() const;
	QRect leftTextRect() const;
	QRect rightTextRect() const;

	void drawFrame(QPainter &);
	void drawText(QPainter &);
	void drawErrorText(QPainter &);
};

#endif
