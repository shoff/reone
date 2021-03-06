/*
 * Copyright � 2020 Vsevolod Kremianskii
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <memory>
#include <vector>

#include "glm/mat4x4.hpp"
#include "glm/vec2.hpp"

#include "../resources/gfffile.h"

#include "control/control.h"

namespace reone {

namespace gui {

static const int kDefaultResolutionX = 640;
static const int kDefaultResolutionY = 480;

class GUI : public render::IEventHandler {
public:
    bool handle(const SDL_Event &event) override;
    void update(float dt);

    virtual void initGL();
    void render() const;
    void render3D() const;

    void resetFocus();

protected:
    enum class ScalingMode {
        Center,
        PositionRelativeToCenter,
        Stretch
    };

    render::GraphicsOptions _gfxOpts;
    int _resolutionX { kDefaultResolutionX };
    int _resolutionY { kDefaultResolutionY };
    ScalingMode _scaling { ScalingMode::Center };
    float _aspect { 0.0f };
    glm::ivec2 _screenCenter { 0 };
    glm::ivec2 _rootOffset { 0 };
    glm::ivec2 _controlOffset { 0 };
    std::shared_ptr<render::Texture> _background;
    std::shared_ptr<Control> _rootControl;
    std::vector<std::shared_ptr<Control>> _controls;
    std::shared_ptr<Control> _focus;

    GUI(const render::GraphicsOptions &opts);

    void load(const std::string &resRef, BackgroundType background);
    void loadBackground(BackgroundType type);
    void showControl(const std::string &tag);
    void hideControl(const std::string &tag);

    Control &getControl(const std::string &tag) const;

    virtual bool handleKeyDown(SDL_Scancode key);
    virtual bool handleKeyUp(SDL_Scancode key);

    virtual void onFocusChanged(const std::string &control, bool focus);
    virtual void onClick(const std::string &control);
    virtual void onItemClicked(const std::string &control, const std::string &item);

private:
    GUI(const GUI &) = delete;
    GUI &operator=(const GUI &) = delete;

    void positionRelativeToCenter(Control &control);
    void stretchControl(Control &control);
    void updateFocus(int x, int y);
    void drawBackground() const;
};

} // namespace gui

} // namespace reone
