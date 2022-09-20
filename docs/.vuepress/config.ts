import { defineUserConfig } from "@vuepress/cli";
import { defaultTheme } from "@vuepress/theme-default";

import {
	locales,
	navbartw,
	navbaren,
	sidebartw,
	sidebaren,
	notFound,
	plugins,
} from "./configs";

const config = defineUserConfig({
	// 設定檔
	base: "/ArduinoLib/", // 默認位置
	lang: "zh-TW", // 語言
	title: "夜空工作室", // 標題
	description: "夜空工作室", // 描述
	head: [
		// 額外的 head 標籤
		["meta", { charset: "utf-8" }],
		["meta", { name: "theme-color", content: "#22272e" }],
		[
			"link",
			{
				rel: "icon",
				href: "https://avatars.githubusercontent.com/u/111264458?s=400&u=a1374e7a15033b696e1ca5f897d9e8160cc8029e&v=4",
			},
		],
	],

	locales,

	// theme and its config
	theme: defaultTheme({
		home: "/",
		logo: "https://avatars.githubusercontent.com/u/111264458?s=400&u=a1374e7a15033b696e1ca5f897d9e8160cc8029e&v=4",

		sidebarDepth: 3,
		repo: "https://github.com/NightSky-Studio/ArduinoLib",
		docsRepo: "https://github.com/NightSky-Studio/ArduinoLib",
		docsBranch: "main",
		docsDir: "docs",
		editLink: true,
		editLinkPattern: ":repo/edit/:branch/:path",
		lastUpdated: true,
		contributors: true,

		locales: {
			"/": {
				notFound,
				navbar: navbartw,
				sidebar: sidebartw,
				selectLanguageText: "選擇語言",
				selectLanguageName: "繁體中文",
				lastUpdatedText: "最後更新",
				editLinkText: "在 GitHub 上編輯此頁面",
				contributorsText: "貢獻者",
				backToHome: "回到首頁",
				toggleColorMode: "切換顏色模式",
				openInNewWindow: "在新視窗中開啟",
				toggleSidebar: "切換導覽列",
				tip: "提示",
				warning: "注意",
				danger: "警告",
			},
			"/en/": {
				navbar: navbaren,
				sidebar: sidebaren,
				selectLanguageText: "Select Language",
				selectLanguageName: "English",
				editLinkText: "Edit this page on GitHub",
			},
		},
	}),

	// plugins config
	plugins,
});

export default config;
