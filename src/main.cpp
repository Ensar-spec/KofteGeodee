#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

// Oyun başarıyla yüklendiğinde çalışacak hile kodu
$on_mod(Loaded) {
    log::info("Kofte Premium Geode yuklendi!");

    // Oyunun istatistik yöneticisine erişiyoruz
    auto GSM = GameStatsManager::sharedState();
    if (GSM) {
        // "5" ID'si Mana Orbs (Mavi Top) temsil eder, burayı 542345 yapıyoruz
        GSM->setStat("5", 542345);
        log::info("Mavi top sayisi 542345 olarak güncellendi!");
    }
}

// NOCLIP HİLESİ (Karakterin engellere çarpsa bile ölmesini engeller)
class $modify(MyPlayLayer, PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* object) {
        // Normal ölüm fonksiyonunun içini boş bırakıp erken döndürerek (return)
        // oyuncunun patlamasını ve ölmesini tamamen iptal ediyoruz.
        log::info("Noclip engeli yakaladi, olum iptal edildi!");
        return; 
    }
};
