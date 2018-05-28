core = 7.x
api = 2

projects[drupal][type] = core
projects[drupal][version] = 7.59

; RELEASE
; Leave in place for replacement by release process.
projects[devmaster][type] = profile
projects[devmaster][download][type] = git
projects[devmaster][download][branch] = cloudrup
projects[devmaster][download][url] = https://github.com/ipumpkin/devmaster.git