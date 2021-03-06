# # ~/.bashrc: executed by bash(1) for non-login shells.
# # see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# # for examples
# # [[ $- == *i* ]] && source ~/.local/share/blesh/ble.sh --attach=none

# # If not running interactively, don't do anything
# case $- in
#     *i*) ;;
#       *) return;;
# esac

# # don't put duplicate lines or lines starting with space in the history.
# # See bash(1) for more options
# HISTCONTROL=ignoreboth

# # append to the history file, don't overwrite it
# shopt -s histappend

# # for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
# HISTSIZE=1000
# HISTFILESIZE=2000

# # check the window size after each command and, if necessary,
# # update the values of LINES and COLUMNS.
# shopt -s checkwinsize

# # If set, the pattern "**" used in a pathname expansion context will
# # match all files and zero or more directories and subdirectories.
# #shopt -s globstar

# # make less more friendly for non-text input files, see lesspipe(1)
# [ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"

# # set variable identifying the chroot you work in (used in the prompt below)
# if [ -z "${debian_chroot:-}" ] && [ -r /etc/debian_chroot ]; then
#     debian_chroot=$(cat /etc/debian_chroot)
# fi

# # set a fancy prompt (non-color, unless we know we "want" color)
# case "$TERM" in
#     xterm-color|*-256color) color_prompt=yes;;
# esac

# # uncomment for a colored prompt, if the terminal has the capability; turned
# # off by default to not distract the user: the focus in a terminal window
# # should be on the output of commands, not on the prompt
# # force_color_prompt=yes

# if [ -n "$force_color_prompt" ]; then
#     if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
# 	# We have color support; assume it's compliant with Ecma-48
# 	# (ISO/IEC-6429). (Lack of such support is extremely rare, and such
# 	# a case would tend to support setf rather than setaf.)
# 	color_prompt=yes
#     else
# 	color_prompt=
#     fi
# fi
# # PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '

# if [ "$color_prompt" = yes ]; then
#     PS1='${debian_chroot:+($debian_chroot)}\[\033[01;36m\]\W \[\033[01;32m\]➜ \[\033[00m\] '
# else
#     PS1='${debian_chroot:+($debian_chroot)}$ '
# fi
# unset color_prompt force_color_prompt

# # If this is an xterm set the title to user@host:dir
# case "$TERM" in
# xterm*|rxvt*)
#     PS1="\[\e]0;${debian_chroot:+($debian_chroot)}]$PS1"
#     ;;
# *)
#     ;;
# esac

# # enable color support of ls and also add handy aliases
# if [ -x /usr/bin/dircolors ]; then
#     test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
#     alias ls='ls --color=auto'
#     #alias dir='dir --color=auto'
#     #alias vdir='vdir --color=auto'

#     alias grep='grep --color=auto'
#     alias fgrep='fgrep --color=auto'
#     alias egrep='egrep --color=auto'
# fi

# # colored GCC warnings and errors
# export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'

# # some more ls aliases
# alias ll='ls -alF'
# alias la='ls -A'
# alias l='ls -CF'

# # Add an "alert" alias for long running commands.  Use like so:
# #   sleep 10; alert
# alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|sed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'

# # Alias definitions.
# # You may want to put all your additions into a separate file like
# # ~/.bash_aliases, instead of adding them here directly.
# # See /usr/share/doc/bash-doc/examples in the bash-doc package.

# if [ -f ~/.bash_aliases ]; then
#     . ~/.bash_aliases
# fi

# # enable programmable completion features (you don't need to enable
# # this, if it's already enabled in /etc/bash.bashrc and /etc/profile
# # sources /etc/bash.bashrc).
# if ! shopt -oq posix; then
#   if [ -f /usr/share/bash-completion/bash_completion ]; then
#     . /usr/share/bash-completion/bash_completion
#   elif [ -f /etc/bash_completion ]; then
#     . /etc/bash_completion
#   fi
# fi

# export NVM_DIR="$HOME/.nvm"
# [ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
# [ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion

# export PATH=$PATH:/home/priyanshu/ns-allinone-2.35/bin:/home/priyanshu/ns-allinone-2.35/tcl8.5.10/unix:/home/priyanshu/ns-allinone-2.35/tk8.5.10/unix

# export LD_LIBRARY_PATH=/home/priyanshu/ns-allinone-2.35/otcl-1.14:/home/priyanshu/ns-allinone-2.35/lib

# source <(kubectl completion bash)

# new_line_ps1() {
#   local _ y x _
# #   local LIGHT_YELLOW="\001\033[1;93m\002"
#   local     RESET="\001\e[0m\002"

#   IFS='[;' read -p $'\e[6n' -d R -rs _ y x _
#   if [[ "$x" != 1 ]]; then
#     printf "\n${RESET}"
#   fi
# }

# PS1="\$(new_line_ps1)$PS1"


# # eval "$(starship init bash)"

# # [[ ${BLE_VERSION-} ]] && ble-attach

#
# ~/.bashrc
#

# ble.sh start
[[ $- == *i* ]] &&
  source "$HOME/.local/share/blesh/ble.sh" --rcfile "$HOME/.blerc"

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

# Use bash-completion, if available
[[ $PS1 && -f /usr/share/bash-completion/bash_completion ]] && \
    . /usr/share/bash-completion/bash_completion

# aliases
alias ls='ls --color=auto'
alias mirrors='sudo ~/.mirror.sh'
alias cp="cp -i"
alias mv='mv -i'
alias rm='rm -i'
alias steam='prime-run steam'

PS1='[\u@\h \W]\$ '

# env variables
export CHROME_EXECUTABLE=chromium
export TERM="xterm-256color"
export HISTCONTROL=ignoredups:erasedups
export MICRO_TRUECOLOR=1
export EDITOR=micro

# export paths
export PATH=$PATH:~/flutter/bin
export PATH=$PATH:~/android_sdk/cmdline-tools/latest/bin
export PATH=$PATH:~/android_sdk/platform-tools
export PATH=$PATH:~/.npm-global/bin

shopt -s cdspell 
shopt -s expand_aliases
shopt -s checkwinsize
shopt -s histappend

bind "set completion-ignore-case on"

stty -ixon

# add new line at the end of file to present prompt neatly, tho not required in starship
new_line_ps1() {
  local _ y x _
  local RESET='\001\e[0m\002'
  IFS='[;' read -p $'\e[6n' -d R -rs _ y x _
  if [[ "$x" != 1 ]]; then
    printf "\n${RESET}"
  fi
}

PS1="\$(new_line_ps1)$PS1"

# fzf magic
source /usr/share/fzf/key-bindings.bash
source /usr/share/fzf/completion.bash

# starship init
eval "$(starship init bash)"

# ble.sh end
[[ ${BLE_VERSION-} ]] && ble-attach
