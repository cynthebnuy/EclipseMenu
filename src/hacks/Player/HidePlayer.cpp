#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

#include <Geode/modify/PlayerObject.hpp>

namespace eclipse::hacks::Player {
    class $hack(ForceGhostTrail) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");
            tab->addToggle("player.forceghosttrail")->setDescription()->handleKeybinds();
        }
      
        [[nodiscard]] const char* getId() const override { return "Force Ghost Trail"; }
    };

    REGISTER_HACK(ForceGhostTrail)
    
    class $modify(PlayerObjectFGTHook, PlayerObject){
        ADD_HOOKS_DELEGATE("player.forceghosttrail")
        void toggleGhostEffect(GhostType p0) {
            p0 = GhostType::Enabled;
            PlayerObject::toggleGhostEffect(p0);
        }
    };
}
