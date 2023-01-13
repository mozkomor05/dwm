#!/usr/bin/env bash

## Author  : Aditya Shakya
## Mail    : adi1090x@gmail.com
## Github  : @adi1090x
## Twitter : @adi1090x

# Available Styles
# >> Created and tested on : rofi 1.6.0-1
#
# style_1     style_2     style_3     style_4     style_5     style_6
# style_7     style_8     style_9     style_10    style_11    style_12

theme="style"
dir="$HOME/.config/rofi/launchers/launcher"

# dark
# ALPHA="#00000000"
# BG="#15161E"
# FG="#c0caf5"
# SELECT="#1a1b26"

# light
#ALPHA="#00000000"
#BG="#FFFFFFff"
#FG="#000000ff"
#SELECT="#f3f3f3ff"

# accent colors
# COLORS=('#f7768e' '#e0af68' '#7dcfff' '#a9b1d6' '#ebcb8d' '#bb9af7' '#c0caf5' \
# 			'#9ece6a' '#7aa2f7' '#db4b4b' '#ff9e64')
# ACCENT="${COLORS[$(( $RANDOM % 11 ))]}ff"
# overwrite colors file
# cat > $dir/colors.rasi <<- EOF
# 	/* colors */
# 
# 	* {
# 	  al:  $ALPHA;
# 	  bg:  $BG;
# 	  se:  $SELECT;
# 	  fg:  $FG;
# 	  ac:  $ACCENT;
# 	}
# EOF

# comment these lines to disable random style
#themes=($(ls -p --hide="launcher.sh" --hide="colors.rasi" $dir))
#theme="${themes[$(( $RANDOM % 12 ))]}"

rofi -no-lazy-grab -show drun -modi drun -theme $dir/"$theme"
