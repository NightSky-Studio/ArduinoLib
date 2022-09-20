import type { PluginConfig } from "@vuepress/core";
import { searchPlugin } from "@vuepress/plugin-search";
import { docsearchPlugin } from "@vuepress/plugin-docsearch";
import { mediumZoomPlugin } from "@vuepress/plugin-medium-zoom";

export const plugins: PluginConfig = [
	searchPlugin({
		locales: {
			"/": {
				placeholder: "搜索",
			},
			"/en/": {
				placeholder: "Search",
			},
		},
		maxSuggestions: 10,
	}),

	// 圖片縮放
	mediumZoomPlugin({
		selector: ":not(a) > img",
		delay: 1000,
	}),
];

export default plugins;
