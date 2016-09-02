#include <QtGui>
#include "typingarea.h"
#include <QtDebug>

TypingArea::TypingArea(QWidget *parent) : QWidget(parent) {
    text = "";
    errorText = "";

    textFont = QFont("Helvetica", 85, QFont::Bold, false); // � �������� ������ 35 �������� ���������
    frameWidth = 6;
    frameRadius = 8;
    textMargin = 6;
    textColor.setRgb(129, 86, 60);
    curSymbolColor.setRgb(12, 208, 218);
    frameColor.setRgb(197, 174, 2);
    backColor.setRgb(255, 224, 97);
    typedMaskColor.setRgb(160, 160, 160, 170);

    typedTextPercent = TYPED_TEXT_PERCENT;
    shift = 0;

    setStyleSheet(styleSheet() + frameStylesheet());
    setFont(textFont);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    setFocusPolicy(Qt::StrongFocus);
}

//--------------------------------------------------------------------
//--------------------------------------------------------------------

void TypingArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(fullBackRect(), backColor);
    drawText(painter);
    painter.fillRect(leftBackRect(), typedMaskColor);
    if(!errorText.isEmpty()) {
        painter.fillRect(rightBackRect(), QColor(255, 0, 0, 210));
        drawErrorText(painter);
    }
    drawFrame(painter);
}

void TypingArea::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Backspace) {
        if(!errorText.isEmpty())
            errorText.remove(errorText.length() - 1, 1);
        update(fullBackRect());
        return;
    }

    if(event->text().isEmpty() || curSymbol >= text.length()) {
        QWidget::keyPressEvent(event);
        return;
    }

    if((errorText.isEmpty()) && (event->text()[0] == text[curSymbol])) {
        shift += fontMetrics().width(text[curSymbol]);
        shiftStep = shift / SHIFT_STEPS;
        shiftTimer = startTimer(SHIFT_INTERVAL);
        curSymbol++;
    } else {
        errorText += event->text();
        update(fullBackRect());
    }
}

void TypingArea::timerEvent(QTimerEvent *event) {
    if(event->timerId() == shiftTimer) {
        if(shift > shiftStep) {
            shift -= shiftStep;
        } else {
            shift = 0;
            killTimer(shiftTimer);
        }
        update(fullBackRect());
    }
}

QSize TypingArea::sizeHint() const {
    int w = NORMAL_TEXT_LENGTH * fontMetrics().width('x')
            + 2 * (textMargin + frameWidth);
    int h = fontMetrics().height() * CUR_SYMBOL_ZOOM / 100
            + 2 * (textMargin + frameWidth);

    return QSize(w, h);
}

QSize TypingArea::minimumSizeHint() const {
    int w = MIN_TEXT_LENGTH * fontMetrics().width('x')
            + 2 * (textMargin + frameWidth);
    int h = fontMetrics().height() * CUR_SYMBOL_ZOOM / 100
            + 2 * (textMargin + frameWidth);

    return QSize(w, h);
}

//--------------------------------------------------------------------
//--------------------------------------------------------------------

void TypingArea::drawFrame(QPainter &painter) {
    QStyleOptionFrameV3 opt;
    opt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Frame, &opt, &painter, this);
}

void TypingArea::drawText(QPainter &painter) {
    painter.setClipRect(fullTextRect());

    QFont curSymbolFont = textFont;
    curSymbolFont.setPointSizeF(curSymbolFont.pointSizeF() * CUR_SYMBOL_ZOOM / 100);

    painter.setPen(curSymbolColor);
    painter.setFont(curSymbolFont);
    painter.drawText(rightTextRect().adjusted(shift, 0, 0, 0),
            Qt::AlignLeft | Qt::AlignVCenter | Qt::TextSingleLine,
            text.mid(curSymbol, 1));

    int curSymbolWidth = painter.fontMetrics().width(text[curSymbol]);

    painter.setPen(textColor);
    painter.setFont(textFont);

    QString str;
    int width;
    int cur;

    cur = curSymbol - 1;
    width = leftTextRect().width() + shift;
    while((width > 0) && (cur >= 0)) {
        str = text[cur] + str;
        width -= fontMetrics().width(text[cur--]);
    }

    painter.drawText(leftTextRect().adjusted(0, 0, shift, 0),
            Qt::AlignRight | Qt::AlignVCenter | Qt::TextSingleLine,	str);

    str.clear();
    cur = curSymbol + 1;
    width = rightTextRect().width();
    while((width > 0) && (cur < text.length())) {
        str += text[cur];
        width -= fontMetrics().width(text[cur++]);
    }

    painter.drawText(rightTextRect().adjusted(shift + curSymbolWidth, 0, 0, 0),
            Qt::AlignLeft | Qt::AlignVCenter | Qt::TextSingleLine, str);

    painter.setClipRect(rect());
}

void TypingArea::drawErrorText(QPainter &painter) {
    painter.setPen(Qt::white);
    QRect boundRect = painter.boundingRect(rightTextRect(),
            Qt::AlignLeft | Qt::AlignVCenter | Qt::TextSingleLine, errorText);

    painter.setClipRect(rightTextRect());
    if(boundRect.width() <= rightTextRect().width())
        painter.drawText(rightTextRect(),
                Qt::AlignLeft | Qt::AlignVCenter | Qt::TextSingleLine,
                errorText);
    else
        painter.drawText(rightTextRect(),
                Qt::AlignRight | Qt::AlignVCenter | Qt::TextSingleLine,
                errorText);
    painter.setClipRect(rect());
}


QString TypingArea::frameStylesheet() const {
    QString col = QString("rgb(%1, %2, %3)").arg(frameColor.red())
            .arg(frameColor.green()).arg(frameColor.blue());

    QString ss = QString("TypingArea { "
                "border-style: solid; "
                "border-width: %1px; "
                "border-radius: %2px;"
                "padding: %3px; "
                "border-color: %4; }").arg(frameWidth).arg(frameRadius)
                .arg(textMargin).arg(col);
    return ss;
}

//--------------------------------------------------------------------
//--------------------------------------------------------------------

QRect TypingArea::leftBackRect() const {
    return fullBackRect().adjusted(0, 0, - fullBackRect().width()
            * (100 - typedTextPercent) / 100, 0);
}

QRect TypingArea::rightBackRect() const {
    return fullBackRect().adjusted(fullBackRect().width()
            * typedTextPercent / 100, 0, 0, 0);
}

QRect TypingArea::fullBackRect() const {
    return rect().adjusted(frameWidth, frameWidth, -frameWidth, -frameWidth);
}

QRect TypingArea::leftTextRect() const {
    return leftBackRect().adjusted(textMargin, 0, 0, 0);
}

QRect TypingArea::rightTextRect() const {
    return rightBackRect().adjusted(0, 0, -textMargin, 0);
}

QRect TypingArea::fullTextRect() const {
    return fullBackRect().adjusted(textMargin, 0, -textMargin, 0);
}
