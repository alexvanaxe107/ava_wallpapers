# ava_wallpapers

ava_wallpapers is a personal tool to set and organize my wallpapers.

This project is only a recreational/educational project. The porpose is to program something freely that may be useful.

The main languages will be C++ and bash script.

# Roadmap

- Fazer um banco de dados com as imagens
- Colocar a qual tema as imagens pertencem
- Cadastrar multiplos rotulos/tags para as imagens
- Guardar metadados das imagens (tamanho, dimensoes)
- Filtrar as imagens

# Uso

A ideia é criar uma ferramenta cli, na qual possamos iteragir com esta base. Os comandos seriam.

> ava_wp -a arquivo.img identificador_unico (add/inclui inclui essa imagem na base dados com o identificador unico dela)
>ava_wm -t "tag1,tag2,tag3" imagem (identificador ou caminho)
>ava_wm -q -t "tag1" (retorna o caminho das imagens com tag1)
>ava_wm -q -d "1920x1080" (retorna o caminho das imagens com dimensoes 1920x1080)
>ava_wm -q -d "1920x1080" -t "tag1,tag3" (retorna o caminho das imagens com dimensoes 1920x1080 que tenham a tag1 e a tag3)
>ava_wm -q -d "1920x1080" -t "tag1,~tag3" (retorna o caminho das imagens com dimensoes 1920x1080 que tenham a tag1 e NAO tenham a tag3)

# Estrutura
* flake.* - This files are for development and install in a nix system.
* wallpaper_project - The project itself
* src - The code
* include - The headers
* tools - Scripts used to facilitate de development
