#include "Player.h"
#include "Chat.h"
#include "World.h"
#include "boost/date_time.hpp"
#include "Config.h"

class XpWeekend : public PlayerScript
{
    public:
    XpWeekend() : PlayerScript("XpWeekend") { }
    void OnGiveXP(Player* player, uint32& amount, Unit* victim)
{
if(sConfigMgr->GetBoolDefault("DoubleXP.Enable", true))
{
    boost::gregorian::date date(boost::gregorian::day_clock::local_day());
    double day = date.day_of_week();
    if (day == boost::date_time::Thursday ||
        day == boost::date_time::Saturday ||
        day == boost::date_time::Sunday) {

        amount = amount*2; }
		
}
}
    void OnLogin(Player* player, bool firstLogin)
    {
if(sConfigMgr->GetBoolDefault("DoubleXP.Enable", true))
{
        boost::gregorian::date date(boost::gregorian::day_clock::local_day());
    double day = date.day_of_week();
    if (day == boost::date_time::Thursday ||
        day == boost::date_time::Saturday ||
        day == boost::date_time::Sunday) {
        }
}
    }
};

void AddSC_XpWeekend()
{
    new XpWeekend();
}