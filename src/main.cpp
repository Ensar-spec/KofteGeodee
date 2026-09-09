#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // Ana menü açıldığında bildirim çıkarır
        Notification::create("Geode Modu Calisti!", NotificationIcon::Success)->show();

        return true;
    }
};
