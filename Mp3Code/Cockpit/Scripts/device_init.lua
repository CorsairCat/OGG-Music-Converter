dofile(LockOn_Options.script_path.."devices.lua")
dofile(LockOn_Options.script_path.."materials.lua") -- 加载材质

-- Add following lines to your device init
-- ipad controller
creators[devices.IPAD_SYSTEM]     ={"avLuaDevice"           ,LockOn_Options.script_path.."Systems/ipad_ctrl.lua"} 

-- ipad indicator
indicators[#indicators + 1] = {"ccIndicator", LockOn_Options.script_path.."DBGiPad/ipad_init.lua",nil,{{"IPAD_center","IPAD_down","IPAD_right"},{sx_l =  -0.001,}}}

-- Add following lines to your device.lua
devices["IPAD_SYSTEM"]				= counter()

-- Add following lines to your commanddefs.lua
-- in the keys block
-- this part is fpr music player
MusicPauseOrPlay = __custom_counter(),
MusicNext = __custom_counter(),
MusicLast = __custom_counter(),
MusicFastForward = __custom_counter(),
MusicFastBack = __custom_counter(),
MusicLrcViewTrigger = __custom_counter(),
MusicVolUp = __custom_counter(),
MusicVolDown = __custom_counter(),

-- add the following to your input/<devices>/default.lua
-- Music Player
{down = Keys.MusicPauseOrPlay,			name = _('Music Pause/Play'),				category = _('Music Player')},
{down = Keys.MusicVolUp,			    name = _('Music Volume Up'),				category = _('Music Player')},
{down = Keys.MusicVolDown,			    name = _('Music Volume Down'),				category = _('Music Player')},
{down = Keys.MusicNext,			        name = _('Music Play Next'),				category = _('Music Player')},
{down = Keys.MusicLast,			        name = _('Music Play Last'),				category = _('Music Player')},
{down = Keys.MusicFastForward,			name = _('Music Play Fast Forward'),		category = _('Music Player')},
{down = Keys.MusicFastBack,			    name = _('Music Play Fast Backward'),		category = _('Music Player')},
{down = Keys.MusicLrcViewTrigger,		name = _('Music Display Lyrics'),			category = _('Music Player')},