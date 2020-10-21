<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'wordpress' );

/** MySQL database password */
define( 'DB_PASSWORD', '123' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'EtD(aFkcz|.sd]ES7eYyI!gQ/q$GUDYksAVFj7dz(v:__~RM%ah#uAz&a 4b)n^(' );
define( 'SECURE_AUTH_KEY',  'rW<-_E)d-jbd*q>jU]/UWe$l9w)Ng_oPz@1?=; U/*3<GX#B,Zh!fG{iawkNif%9' );
define( 'LOGGED_IN_KEY',    '=/||D=DB%|%jG :pJ%m|6TIu]hrw-eTg%JrRM,j^iqkE0|*M)1/C}B]LT;f4TCQ2' );
define( 'NONCE_KEY',        'R)BK6,/6H@uauHOQ*)sMye#_BGO_Xt9->5=73*<.K[m2NaO@JXGAx<Exp.yC}P;P' );
define( 'AUTH_SALT',        '(f9OF-ZAJai<9p914JF<[<?r!Tljk,s!DD62sRssTF+UEiuf{A)P*`SX%I6/TX2&' );
define( 'SECURE_AUTH_SALT', 'Yg[V-uv N;=>O%jr$Ih,7KgYO;YRP3KQIEc2)^.STF->PJ@NFgct%A~!amV3dZ1p' );
define( 'LOGGED_IN_SALT',   '(+pc](P7v0|&N|%6o4zDhE&uX}vWH? *BQ6yz&~|_]e1 }xork6]scn9<K[,RCMh' );
define( 'NONCE_SALT',       ' H,f>CFz-xdLx/;FxSNY%;5_58c*2<S03Th0F;.I/tjdq8_(]fzk$}[-.fN#;M=A' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';