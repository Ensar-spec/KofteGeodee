#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

// Oyuna girildiğinde Mavi Top sayısını ayarlar
$on_mod(Loaded) {
    log::info("Kofte Premium Geode yuklendi!");

    auto GSM = GameStatsManager::sharedState();
    if (GSM) {
        GSM->setStat("5", 542345);
        log::info("Mavi top sayisi guncellendi!");
    }
}

// NOCLIP HİLESİ (Karakterin ölmesini engeller)
class $modify(MyPlayLayer, PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* object) {
        log::info("Noclip engeli yakaladi, olum engellendi!");
        return; 
    }
};
