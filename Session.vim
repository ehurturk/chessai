let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Dev/Projects/C++/chessai
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +8 src/main.cpp
badd +9 src/engine.cpp
badd +19 include/engine.h
badd +0 term://~/Dev/Projects/C++/chessai//6297:/bin/zsh
badd +13 include/term.h
badd +14 src/term.cpp
argglobal
%argdel
$argadd src/main.cpp
$argadd src/engine.cpp
set stal=2
tabnew
tabnew
tabrewind
edit src/main.cpp
argglobal
2argu
if bufexists("src/main.cpp") | buffer src/main.cpp | else | edit src/main.cpp | endif
if &buftype ==# 'terminal'
  silent file src/main.cpp
endif
balt include/engine.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 6 - ((5 * winheight(0) + 23) / 47)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 6
normal! 019|
tabnext
edit include/engine.h
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 66 + 82) / 164)
exe 'vert 2resize ' . ((&columns * 97 + 82) / 164)
argglobal
if bufexists("include/engine.h") | buffer include/engine.h | else | edit include/engine.h | endif
if &buftype ==# 'terminal'
  silent file include/engine.h
endif
balt src/engine.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 24 - ((23 * winheight(0) + 23) / 47)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 24
normal! 014|
wincmd w
argglobal
if bufexists("src/engine.cpp") | buffer src/engine.cpp | else | edit src/engine.cpp | endif
if &buftype ==# 'terminal'
  silent file src/engine.cpp
endif
balt include/engine.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 26 - ((25 * winheight(0) + 23) / 47)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 26
normal! 0
wincmd w
2wincmd w
exe 'vert 1resize ' . ((&columns * 66 + 82) / 164)
exe 'vert 2resize ' . ((&columns * 97 + 82) / 164)
tabnext
edit include/term.h
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 82 + 82) / 164)
exe 'vert 2resize ' . ((&columns * 81 + 82) / 164)
argglobal
if bufexists("include/term.h") | buffer include/term.h | else | edit include/term.h | endif
if &buftype ==# 'terminal'
  silent file include/term.h
endif
balt src/term.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 9 - ((8 * winheight(0) + 23) / 47)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 9
normal! 02|
wincmd w
argglobal
if bufexists("src/term.cpp") | buffer src/term.cpp | else | edit src/term.cpp | endif
if &buftype ==# 'terminal'
  silent file src/term.cpp
endif
balt include/term.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 17 - ((16 * winheight(0) + 23) / 47)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 17
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 82 + 82) / 164)
exe 'vert 2resize ' . ((&columns * 81 + 82) / 164)
tabnext 2
set stal=1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0&& getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToOFAc
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
