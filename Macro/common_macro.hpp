//　2020/05/18　lightskeleton


//  TODO: プラットフォーム対応ー＞プラットフォームごとのインクルード書くヘッダー用意する。（WindowsかLinux、Unix系ぐらいしかやらないから、不要？）
#include <cassert>
#include <string.h>


#ifndef COMMON_MACRO_HPP
#define COMMON_MACRO_HPP

#define PROJECTSCHEME_DEBUG 1


//  TODO:　プラットフォーム対応ー＞プラットフォーム用ヘッダーへ移動する。
#define CMN_ASSERT(COND) assert(COND)
#define LOG(FORMAT, MSG) printf(FORMAT, MSG);


//アサート
#ifndef CMNASSERT
#if PROJECTSCHEME_DEBUG > 0
  #define CMNASSERT(COND, MSG) do {                                 \
      if (!(COND)) {                                                \
          if (strlen(MSG)) {   \
              LOG("Assert:%s", MSG);               \
          }                                                         \
          CMN_ASSERT(COND);                                         \
      }  \
  } while (0)
#else
  #define CMNASSERT(cond, msg)
#endif
#endif //CMNASSERT

//ヌルチェック
#define CHECK_NULL_RETURN(OBJ, ASSERT_MSG) \
if (!OBJ) { \
    CCASSERT(false, #ASSERT_MSG); \
    return ; \
}

#define CHECK_NULL_RETURN_WITH_VALUE(OBJ, DEF_RET) \
if (!OBJ) { \
    return DEF_RET; \
}

#endif // COMMON_MACRO_HPP