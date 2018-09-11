#pragma once
#include <vector>
#include <fa_nuklear.h>
#include "mouseandclickmenu.h"

namespace FAGui
{
    class GuiManager;

    class CharacterDialoguePopup
    {
    public:
        CharacterDialoguePopup(GuiManager& guiManager);
        virtual ~CharacterDialoguePopup() = default;

        enum class UpdateResult
        {
            DoNothing,
            PopDialog
        };

        void addMenuOption(const std::vector<std::string>& option, std::function<UpdateResult()> action);

        virtual UpdateResult update(struct nk_context* ctx);

        static UpdateResult actionQuit() { return UpdateResult::PopDialog; }
        static UpdateResult actionDoNothing() { return UpdateResult::DoNothing; }

    public:
        std::vector<std::string> mIntroduction;

    private:
        GuiManager& mGuiManager;
        nk_scroll mScroll = {};
        MouseAndClickMenu mDialogMenu;


        std::vector<std::vector<std::string>> mDialogOptions;
        std::vector<std::function<UpdateResult()>> mDialogActions;
    };
}
