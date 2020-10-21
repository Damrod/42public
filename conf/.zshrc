# colored GCC warnings and errors
export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'
# non colored GCC warnings and errors
# export GCC_COLORS=""

# some more ls aliases
# alias ll='ls -alF'

alias ll='ls -alFGt'
alias la='ls -A'
alias l='ls -lh | sort -r | awk '\''NF==9 { if ($1~/^d/) { printf $1 "/" $2 "/" $3 "/" $4 "/" $5 "/" $6 " " $7 "/" $8 " " "\033[1;34m" $9 "\033[0m" "\n" } else { printf $1 "/" $2 "/" $3 "/" $4 "/" $5 "/" $6 " " $7 "/" $8 " " "\033[1;32m" $9 "\033[0m" "\n" } }'\'' | column -t -s"/"'
alias qemacs='emacs-26.3 -Q -nw'
alias emacs='emacs-26.3'
#alias emacs='emacs -nw'
export LDFLAGS="-L/Users/aollero-/.brew/opt/libffi/lib"

export CPPFLAGS="-I/Users/aollero-/.brew/opt/libffi/include"
export PKG_CONFIG_PATH="/Users/aollero-/.brew/opt/libffi/lib/pkgconfig"
export EDITOR='qemacs'
export GUILE_LOAD_PATH="/Users/aollero-/.brew/share/guile/site/3.0"
export GUILE_LOAD_COMPILED_PATH="/Users/aollero-/.brew/lib/guile/3.0/site-ccache"
export GUILE_SYSTEM_EXTENSIONS_PATH="/Users/aollero-/.brew/lib/guile/3.0/extensions"

#PS1="%m%# "
PROMPT="%m:%~%# "
#[%F{34}%n%F{reset}@%F{magenta}%m%F{reset} %.]
# local UP="\033[F"
# local CL="\033[0J"
function proml {
	local UP="\033[1A"
	local CL="\033[0J"
	local PROML=$1
	#PS1="\$ "
	for i in $(seq 0 ${PROML})
		 do
		 local PROMPT_COMMAND_NL="\n${PROMPT_COMMAND_NL}"
		 local PROMPT_COMMAND_UP="${UP}${PROMPT_COMMAND_UP}"
		 done
	export PROMPT_COMMAND_SPACE="${PROMPT_COMMAND_NL}${PROMPT_COMMAND_UP}${CL}"
	PROMPT_COMMAND="echo -ne \"$PROMPT_COMMAND_SPACE\""
	precmd() { eval "$PROMPT_COMMAND" }
}
export PATH=/Users/aollero-/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Library/Frameworks/Mono.framework/Versions/Current/Commands:/Users/aollero-/.brew/bin:/Users/aollero-/.brew/opt/gnu-sed/libexec/gnubin
export MAIL=aollero@gmail.com
