#ifndef SPECIAL_WIDGET_H
#define SPECIAL_WIDGET_H

#include "Widget.h"

class SpecialWidget : public Widget {
public:
    SpecialWidget();

    SpecialWidget(const SpecialWidget& origin);
    SpecialWidget& operator=(const SpecialWidget& rhs);
};

#endif /* SPECIAL_WIDGET_H */
