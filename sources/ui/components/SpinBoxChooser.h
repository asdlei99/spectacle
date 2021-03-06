#pragma once
#include "Widget.hpp"
#include "ui/Geometry.h"
#include <string>
#include <vector>
#include <functional>
class FontEngine;
class ColorPalette;

class SpinBoxChooser : public Widget {
public:
    SpinBoxChooser(Widget *group, FontEngine &fontEngine, ColorPalette &palette);
    void clearChoices();
    void addChoice(int32_t value, const char *text);

    const std::string &textAtIndex(int32_t index);

    int32_t valueIndex() const;
    void setValueIndex(int32_t index);

    int32_t value() const;
    void setValue(int32_t value);

    std::function<void(int32_t)> ValueChangedCallback;

protected:
    void onDisplay() override;
    void onResize(const ResizeEvent &ev) override;
    bool onMouse(const MouseEvent &ev) override;

private:
    void updateLayout();

private:
    int32_t fValueIndex = 0;
    std::vector<std::pair<int32_t, std::string>> fChoices;
    FontEngine &fFontEngine;
    ColorPalette &fPalette;
    Rect fBoundsLeftButton;
    Rect fBoundsRightButton;
    Rect fBoundsCenterLabel;
};
