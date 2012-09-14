#ifndef NAV_TEXTWIDTHCALCULATOR_H
#define NAV_TEXTWIDTHCALCULATOR_H

#include <QFont>
#include <QFontMetrics>

namespace Nav {

// Calculate the width of ASCII-only strings quickly.  Falls back to
// QFontMetricsF::width for strings containing non-ASCII characters.  Should
// work with both kerning (e.g. for "Wv", place v one more pixel left than
// otherwise) and subpixel widths.
class TextWidthCalculator
{
public:
    explicit TextWidthCalculator(QFontMetricsF fontMetricsF);
    int calculate(const QString &text);
    int calculate(const char *text);

private:
    QFontMetricsF m_fontMetricsF;
    qreal m_asciiCharWidths[128][128];
};

} // namespace Nav

#endif // NAV_TEXTWIDTHCALCULATOR_H
