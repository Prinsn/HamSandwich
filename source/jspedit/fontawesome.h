#ifndef FONTAWESOME_H
#define FONTAWESOME_H

#include "globals.h"

enum class FAChar {
    glass = 0xf000,
    music = 0xf001,
    search = 0xf002,
    envelope_o = 0xf003,
    heart = 0xf004,
    star = 0xf005,
    star_o = 0xf006,
    user = 0xf007,
    film = 0xf008,
    th_large = 0xf009,
    th = 0xf00a,
    th_list = 0xf00b,
    check = 0xf00c,
    times = 0xf00d,
    search_plus = 0xf00e,
    search_minus = 0xf010,
    power_off = 0xf011,
    signal = 0xf012,
    cog = 0xf013,
    trash_o = 0xf014,
    home = 0xf015,
    file_o = 0xf016,
    clock_o = 0xf017,
    road = 0xf018,
    download = 0xf019,
    arrow_circle_o_down = 0xf01a,
    arrow_circle_o_up = 0xf01b,
    inbox = 0xf01c,
    play_circle_o = 0xf01d,
    repeat = 0xf01e,
    refresh = 0xf021,
    list_alt = 0xf022,
    lock = 0xf023,
    flag = 0xf024,
    headphones = 0xf025,
    volume_off = 0xf026,
    volume_down = 0xf027,
    volume_up = 0xf028,
    qrcode = 0xf029,
    barcode = 0xf02a,
    tag = 0xf02b,
    tags = 0xf02c,
    book = 0xf02d,
    bookmark = 0xf02e,
    print = 0xf02f,
    camera = 0xf030,
    font = 0xf031,
    bold = 0xf032,
    italic = 0xf033,
    text_height = 0xf034,
    text_width = 0xf035,
    align_left = 0xf036,
    align_center = 0xf037,
    align_right = 0xf038,
    align_justify = 0xf039,
    list = 0xf03a,
    outdent = 0xf03b,
    indent = 0xf03c,
    video_camera = 0xf03d,
    picture_o = 0xf03e,
    pencil = 0xf040,
    map_marker = 0xf041,
    adjust = 0xf042,
    tint = 0xf043,
    pencil_square_o = 0xf044,
    share_square_o = 0xf045,
    check_square_o = 0xf046,
    arrows = 0xf047,
    step_backward = 0xf048,
    fast_backward = 0xf049,
    backward = 0xf04a,
    play = 0xf04b,
    pause = 0xf04c,
    stop = 0xf04d,
    forward = 0xf04e,
    fast_forward = 0xf050,
    step_forward = 0xf051,
    eject = 0xf052,
    chevron_left = 0xf053,
    chevron_right = 0xf054,
    plus_circle = 0xf055,
    minus_circle = 0xf056,
    times_circle = 0xf057,
    check_circle = 0xf058,
    question_circle = 0xf059,
    info_circle = 0xf05a,
    crosshairs = 0xf05b,
    times_circle_o = 0xf05c,
    check_circle_o = 0xf05d,
    ban = 0xf05e,
    arrow_left = 0xf060,
    arrow_right = 0xf061,
    arrow_up = 0xf062,
    arrow_down = 0xf063,
    share = 0xf064,
    expand = 0xf065,
    compress = 0xf066,
    plus = 0xf067,
    minus = 0xf068,
    asterisk = 0xf069,
    exclamation_circle = 0xf06a,
    gift = 0xf06b,
    leaf = 0xf06c,
    fire = 0xf06d,
    eye = 0xf06e,
    eye_slash = 0xf070,
    exclamation_triangle = 0xf071,
    plane = 0xf072,
    calendar = 0xf073,
    random = 0xf074,
    comment = 0xf075,
    magnet = 0xf076,
    chevron_up = 0xf077,
    chevron_down = 0xf078,
    retweet = 0xf079,
    shopping_cart = 0xf07a,
    folder = 0xf07b,
    folder_open = 0xf07c,
    arrows_v = 0xf07d,
    arrows_h = 0xf07e,
    bar_chart_o = 0xf080,
    twitter_square = 0xf081,
    facebook_square = 0xf082,
    camera_retro = 0xf083,
    key = 0xf084,
    cogs = 0xf085,
    comments = 0xf086,
    thumbs_o_up = 0xf087,
    thumbs_o_down = 0xf088,
    star_half = 0xf089,
    heart_o = 0xf08a,
    sign_out = 0xf08b,
    linkedin_square = 0xf08c,
    thumb_tack = 0xf08d,
    external_link = 0xf08e,
    sign_in = 0xf090,
    trophy = 0xf091,
    github_square = 0xf092,
    upload = 0xf093,
    lemon_o = 0xf094,
    phone = 0xf095,
    square_o = 0xf096,
    bookmark_o = 0xf097,
    phone_square = 0xf098,
    twitter = 0xf099,
    facebook = 0xf09a,
    github = 0xf09b,
    unlock = 0xf09c,
    credit_card = 0xf09d,
    rss = 0xf09e,
    hdd_o = 0xf0a0,
    bullhorn = 0xf0a1,
    bell = 0xf0f3,
    certificate = 0xf0a3,
    hand_o_right = 0xf0a4,
    hand_o_left = 0xf0a5,
    hand_o_up = 0xf0a6,
    hand_o_down = 0xf0a7,
    arrow_circle_left = 0xf0a8,
    arrow_circle_right = 0xf0a9,
    arrow_circle_up = 0xf0aa,
    arrow_circle_down = 0xf0ab,
    globe = 0xf0ac,
    wrench = 0xf0ad,
    tasks = 0xf0ae,
    filter = 0xf0b0,
    briefcase = 0xf0b1,
    arrows_alt = 0xf0b2,
    users = 0xf0c0,
    link = 0xf0c1,
    cloud = 0xf0c2,
    flask = 0xf0c3,
    scissors = 0xf0c4,
    files_o = 0xf0c5,
    paperclip = 0xf0c6,
    floppy_o = 0xf0c7,
    square = 0xf0c8,
    bars = 0xf0c9,
    list_ul = 0xf0ca,
    list_ol = 0xf0cb,
    strikethrough = 0xf0cc,
    underline = 0xf0cd,
    table = 0xf0ce,
    magic = 0xf0d0,
    truck = 0xf0d1,
    pinterest = 0xf0d2,
    pinterest_square = 0xf0d3,
    google_plus_square = 0xf0d4,
    google_plus = 0xf0d5,
    money = 0xf0d6,
    caret_down = 0xf0d7,
    caret_up = 0xf0d8,
    caret_left = 0xf0d9,
    caret_right = 0xf0da,
    columns = 0xf0db,
    sort = 0xf0dc,
    sort_asc = 0xf0dd,
    sort_desc = 0xf0de,
    envelope = 0xf0e0,
    linkedin = 0xf0e1,
    undo = 0xf0e2,
    gavel = 0xf0e3,
    tachometer = 0xf0e4,
    comment_o = 0xf0e5,
    comments_o = 0xf0e6,
    bolt = 0xf0e7,
    sitemap = 0xf0e8,
    umbrella = 0xf0e9,
    clipboard = 0xf0ea,
    lightbulb_o = 0xf0eb,
    exchange = 0xf0ec,
    cloud_download = 0xf0ed,
    cloud_upload = 0xf0ee,
    user_md = 0xf0f0,
    stethoscope = 0xf0f1,
    suitcase = 0xf0f2,
    bell_o = 0xf0a2,
    coffee = 0xf0f4,
    cutlery = 0xf0f5,
    file_text_o = 0xf0f6,
    building_o = 0xf0f7,
    hospital_o = 0xf0f8,
    ambulance = 0xf0f9,
    medkit = 0xf0fa,
    fighter_jet = 0xf0fb,
    beer = 0xf0fc,
    h_square = 0xf0fd,
    plus_square = 0xf0fe,
    angle_double_left = 0xf100,
    angle_double_right = 0xf101,
    angle_double_up = 0xf102,
    angle_double_down = 0xf103,
    angle_left = 0xf104,
    angle_right = 0xf105,
    angle_up = 0xf106,
    angle_down = 0xf107,
    desktop = 0xf108,
    laptop = 0xf109,
    tablet = 0xf10a,
    mobile = 0xf10b,
    circle_o = 0xf10c,
    quote_left = 0xf10d,
    quote_right = 0xf10e,
    spinner = 0xf110,
    circle = 0xf111,
    reply = 0xf112,
    github_alt = 0xf113,
    folder_o = 0xf114,
    folder_open_o = 0xf115,
    smile_o = 0xf118,
    frown_o = 0xf119,
    meh_o = 0xf11a,
    gamepad = 0xf11b,
    keyboard_o = 0xf11c,
    flag_o = 0xf11d,
    flag_checkered = 0xf11e,
    terminal = 0xf120,
    code = 0xf121,
    reply_all = 0xf122,
    mail_reply_all = 0xf122,
    star_half_o = 0xf123,
    location_arrow = 0xf124,
    crop = 0xf125,
    code_fork = 0xf126,
    chain_broken = 0xf127,
    question = 0xf128,
    info = 0xf129,
    exclamation = 0xf12a,
    superscript = 0xf12b,
    subscript = 0xf12c,
    eraser = 0xf12d,
    puzzle_piece = 0xf12e,
    microphone = 0xf130,
    microphone_slash = 0xf131,
    shield = 0xf132,
    calendar_o = 0xf133,
    fire_extinguisher = 0xf134,
    rocket = 0xf135,
    maxcdn = 0xf136,
    chevron_circle_left = 0xf137,
    chevron_circle_right = 0xf138,
    chevron_circle_up = 0xf139,
    chevron_circle_down = 0xf13a,
    html5 = 0xf13b,
    css3 = 0xf13c,
    anchor = 0xf13d,
    unlock_alt = 0xf13e,
    bullseye = 0xf140,
    ellipsis_h = 0xf141,
    ellipsis_v = 0xf142,
    rss_square = 0xf143,
    play_circle = 0xf144,
    ticket = 0xf145,
    minus_square = 0xf146,
    minus_square_o = 0xf147,
    level_up = 0xf148,
    level_down = 0xf149,
    check_square = 0xf14a,
    pencil_square = 0xf14b,
    external_link_square = 0xf14c,
    share_square = 0xf14d,
    compass = 0xf14e,
    caret_square_o_down = 0xf150,
    caret_square_o_up = 0xf151,
    caret_square_o_right = 0xf152,
    eur = 0xf153,
    gbp = 0xf154,
    usd = 0xf155,
    inr = 0xf156,
    jpy = 0xf157,
    rub = 0xf158,
    krw = 0xf159,
    btc = 0xf15a,
    file = 0xf15b,
    file_text = 0xf15c,
    sort_alpha_asc = 0xf15d,
    sort_alpha_desc = 0xf15e,
    sort_amount_asc = 0xf160,
    sort_amount_desc = 0xf161,
    sort_numeric_asc = 0xf162,
    sort_numeric_desc = 0xf163,
    thumbs_up = 0xf164,
    thumbs_down = 0xf165,
    youtube_square = 0xf166,
    youtube = 0xf167,
    xing = 0xf168,
    xing_square = 0xf169,
    youtube_play = 0xf16a,
    dropbox = 0xf16b,
    stack_overflow = 0xf16c,
    instagram = 0xf16d,
    flickr = 0xf16e,
    adn = 0xf170,
    bitbucket = 0xf171,
    bitbucket_square = 0xf172,
    tumblr = 0xf173,
    tumblr_square = 0xf174,
    long_arrow_down = 0xf175,
    long_arrow_up = 0xf176,
    long_arrow_left = 0xf177,
    long_arrow_right = 0xf178,
    apple = 0xf179,
    windows = 0xf17a,
    android = 0xf17b,
    linux_ = 0xf17c,
    dribbble = 0xf17d,
    skype = 0xf17e,
    foursquare = 0xf180,
    trello = 0xf181,
    female = 0xf182,
    male = 0xf183,
    gittip = 0xf184,
    sun_o = 0xf185,
    moon_o = 0xf186,
    archive = 0xf187,
    bug = 0xf188,
    vk = 0xf189,
    weibo = 0xf18a,
    renren = 0xf18b,
    pagelines = 0xf18c,
    stack_exchange = 0xf18d,
    arrow_circle_o_right = 0xf18e,
    arrow_circle_o_left = 0xf190,
    caret_square_o_left = 0xf191,
    dot_circle_o = 0xf192,
    wheelchair = 0xf193,
    vimeo_square = 0xf194,
    try_ = 0xf195,
    plus_square_o = 0xf196,
};

namespace FA {

inline wchar_t ch(FAChar ch) {
    return (wchar_t) ch;
}

inline std::string str(FAChar ch) {
    int i = (int) ch;
    uint8_t result[3] = {
        0xef,
        (uint8_t)(0x80 | ((i >> 6) & 0x3f)),
        (uint8_t)(0x80 | (i & 0x3f)),
    };
    return std::string((char*) result, 3);
}

}

#endif // FONTAWESOME_H