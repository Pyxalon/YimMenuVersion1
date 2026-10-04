#include "backend/command.hpp"
#include "script_global.hpp"
#include "pointers.hpp"

namespace big
{
    class good_behavior_bonus : command
    {
        using command::command;

        virtual void execute(const command_arguments&, const std::shared_ptr<command_context> ctx) override
		{
			if (!*g_pointers->m_gta.m_is_session_started)
			{
				*script_global(2697074).as<int*>() = 2000; // Money Reward
				*script_global(2697073).as<int*>() = 1;    // Trigger Good behavior bonus
			}
			else
			{
				g_notification_service.push_error("Recovery", "You must be online");
			}
		}
    };

    good_behavior_bonus g_good_behavior_bonus("goodbehaviorbonus", "Good Behavior Bonus", "Triggers the Good Behavior Bonus", 0);
}
