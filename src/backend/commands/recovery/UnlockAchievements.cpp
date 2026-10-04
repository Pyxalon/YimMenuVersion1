#include "backend/command.hpp"
#include "script_global.hpp"
#include "pointers.hpp"
#include "natives.hpp"
#include "fiber_pool.hpp"
#include "services/notifications/notification_service.hpp"
#include "script.hpp"

namespace big
{
	class unlock_achievements : command
	{
		using command::command;

		virtual void execute(const command_arguments&, const std::shared_ptr<command_context> ctx) override
		{
			if (!*g_pointers->m_gta.m_is_session_started)
			{
				g_notification_service.push_error("Recovery", "You must be online");

				return;
			}

			g_fiber_pool->queue_job([] {
				for (int id = 1; id <= 77; ++id)
				{
					auto base = script_global(4525223);

					*base.at(1).as<int*>() = id;
					*base.at(2).as<int*>() = 1;

					script::get_current()->yield(150ms);
				}
				STATS::STAT_SAVE(0, 0, 3, 0);

				g_notification_service.push_success("Recovery", "All achievements unlocked");
			});
		}
	};

    unlock_achievements g_unlock_achievements("unlockachievements", "Unlock Achievements", "Unlock all achievements", 0);
}
